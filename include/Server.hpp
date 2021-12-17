#include <utility>

#include "NetConnection.hpp"
#include "NetThreadSafeQueue.hpp"

struct Msg
{
    uint32_t _id;
    std::string _data;
    Msg() = delete;
    Msg(uint32_t id, std::string msg): _id(id), _data(std::move(msg)) {}
    friend std::ostream& operator << (std::ostream& out, const Msg& m)
    {
        out << "ID: " << m._id << " Data: " << m._data;
        return out;
    }
};

namespace net
{
    class Server
    {
    public:
      Server(uint16_t port, bool encryption) : _acceptor(_context,
         boost::asio::ip::tcp::endpoint(
                 boost::asio::ip::tcp::v4(), port)),
                 _encryption(encryption), _ptr_xtea(std::make_shared<xtea3>())
      {
        Start();
      }

      ~Server()
      {
        Stop();
      }

      void Stop()
      {
          _context.stop();
          if (_thrContext.joinable())
              _thrContext.join();
          std::cout << "[SERVER] Stopped!\n";
      }

      const Msg& Top()
      {
          return _in_logic_messages.front();
      }

      bool Ready()
      {
          return !_in_logic_messages.empty();
      }
      
      Msg Get()
      {
          return _in_logic_messages.pop_front();
      }
      
      size_t NumOfMsgAvailable()
      {
          return _in_logic_messages.size();
      }  

      void Send(const Msg& msg)
      {
          std::unique_lock<std::mutex> ul(_mtx);
          std::shared_ptr<connection> con = GetConn(msg._id);
          if (con != nullptr)
          {
              message m;
              m.header.id = MsgTypes::Logic;
              if (_encryption)
              {
                  uint8_t* tmp_ptr = _ptr_xtea->data_crypt((uint8_t *) msg._data.c_str(), key, msg._data.length() + 1);
                  if (tmp_ptr == nullptr) {
                      std::cerr << "Error encrypt message\n";
                  }
                  m.header.size = _ptr_xtea->get_crypt_size();
                  m.body;
                  for (size_t i = 0; i < m.header.size; i++)
                  {
                      m.body.push_back(tmp_ptr[i]);
                  }
              } else {
                  m.header.size = msg._data.size();
                  m.body;
                  for (auto& it : msg._data)
                  {
                      m.body.push_back(it);
                  }
              }
              MessageClient(con, m);
          } else {
              std::cerr << "No such client: " << msg._id << "\n";
          }
      }

    private:

      void Start()
      {
          try
          {
              WaitForClientConnection();
              _thrContext = std::thread([this]() { _context.run(); });
          }
          catch (std::exception& exc)
          {
              std::cerr << "[SERVER] Unable to start server: " << exc.what() << std::endl;
          }

          std::cout << "[SERVER] Started!\n";

          std::thread UpdateThread([&]()
          {
              while(true)
              {
                  Update(-1, false);
              }
          });
          UpdateThread.detach();
      }

      void WaitForClientConnection()
      {
        _acceptor.async_accept(
                [this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket)
                {
                    if (!ec)
                    {
                        std::cout << "[SERVER] New Connection: " << socket.remote_endpoint() << "\n";
                        std::shared_ptr<connection> newconn =
                                std::make_shared<connection>(connection::owner::server,
                                                             _context, std::move(socket), _in_queue, _encryption, _ptr_xtea);

                        if (OnClientConnect(newconn))
                        {
                            _connections.push_back(newconn);
                            _connections.back()->ConnectToClient(_IdCounter++);
                            std::cout << "[" << _connections.back()->GetId() << "] Connection established!\n";
                        } else {
                            std::cout << "[SERVER] Connection denied by the client.\n";
                        }


                    } else {
                        std::cerr << "[SERVER] New connection Error: " << ec.message() << "\n";
                    }
                    WaitForClientConnection();
                });
      }

      void MessageClient(std::shared_ptr<connection> client, const message& msg)
      {
        if (client && client->IsConnected())
        {
            client->Send(msg);
        } else {
            OnClientDisconnect(client);
            client.reset();
            _connections.erase(
                    std::remove(_connections.begin(),  _connections.end(), client), _connections.end());
        }
      }

      void MessageAllClients(const message& msg, std::shared_ptr<connection> pIgnored = nullptr)
      {
        bool InvalidClientsExists = false;

        for (auto& client : _connections)
        {
            if (client && client->IsConnected())
            {
                if (client != pIgnored)
                    client->Send(msg);
            } else {
                OnClientDisconnect(client);
                client.reset();
                InvalidClientsExists = true;
            }
        }

        if (InvalidClientsExists)
            _connections.erase(
                    std::remove(_connections.begin(),  _connections.end(), nullptr), _connections.end());
      }

      static bool OnClientConnect(const std::shared_ptr<connection>& client)
      {
            return true;
      }

      static void OnClientDisconnect(const std::shared_ptr<connection>& client)
      {
        std::cout << "Removing client [" << client->GetId() << "]\n";
      }

      void OnMessage(std::shared_ptr<connection> client, message& msg)
      {
          switch (msg.header.id)
          {
              case MsgTypes::Handshake:
                  std::cout << "[" << client->GetId() << "] Handshake received!\n";
                  client->Send(msg);
              case MsgTypes::Logic:
                  std::string str = std::string((char*)msg.body.data());
                  Msg tmp = { client->GetId(), str };
                  _in_logic_messages.push_back(tmp);
          }
      }

      void Update(size_t MaxMessages = -1, bool Wait = false)
      {
          if (Wait) _in_queue.wait();
          else  std::this_thread::sleep_for(std::chrono::seconds(1));

          size_t MessagesCount = 0;
          while (MessagesCount < MaxMessages && !_in_queue.empty())
          {
              auto msg = _in_queue.pop_front();
              OnMessage(msg._remote, msg._msg);
              MessagesCount++;
          }
      }

      std::shared_ptr<net::connection> GetConn(uint32_t id)
      {
          for (auto pos: _connections)
          {
              if (pos->GetId() == id)
                  return pos;
          }
          return nullptr;
      }

      tsqueue<Msg> _in_logic_messages;

      tsqueue<owned_message> _in_queue;
      std::deque<std::shared_ptr<connection>> _connections;
      boost::asio::io_context _context;
      std::thread _thrContext;
      boost::asio::ip::tcp::acceptor _acceptor;
      uint32_t _IdCounter = 0;
      std::mutex _mtx;
      bool _encryption;
      std::shared_ptr<xtea3> _ptr_xtea;
      uint32_t key[8] = {0x12, 0x55, 0xAB, 0xF8, 0x12, 0x45, 0x77, 0x1A};
    };
}
