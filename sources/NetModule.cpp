// Copyright 2021 Vedeneev Andrey <vedvedved2003@gmail.com>

#include "NetModule.hpp"

std::string S_TAG = "[SERVER] ";

std::string SERV_STR_0 = S_TAG + "The system has assigned you ID: ";
std::string SERV_STR_1 = "\n" + S_TAG + "Enter your partner's ID. If you want to create a room enter '0': ";
std::string SERV_STR_2 = S_TAG + "Waiting for your partner...\n";

std::mutex mtx, mtx1;
size_t THREAD_COUNT = std::thread::hardware_concurrency();
bool is_on = true;

using std::cout; using std::endl; using std::cerr;

struct Client {
    int id;
    int client_socket;
};

struct Room {
    bool is_full;
    int ID1;
    int ID2;
};

struct Node {
    int _sock;
    std::unique_ptr<Node> _next;
    explicit Node(int sock): _sock(sock), _next(nullptr) {}
    void ToNull() {
        _next.release();
    }
    Node* Next() {
        return _next.get();
    }
    void SetNext(Node* ptr) {
        _next.reset(ptr);
    }
};

    MyQueue::MyQueue(): _first(nullptr), _size(0) {}
    Node* MyQueue::get() {
        std::lock_guard<std::mutex> lg(mtx);
        if (_size) {
            auto* tmp = _first->Next();
            _first->ToNull();
            auto* obj = _first.release();
            _first.reset(tmp);
            _size--;
            return obj;
        }
        return nullptr;
    }
    void MyQueue::add(Node* node) {
        std::lock_guard<std::mutex> lg(mtx1);
        if (_size == 0){
            _first.reset(node);
            _size++;
            return;
        }
        auto* tmp = _first.get();
        for (size_t i = 0; i < _size - 1; ++i) {
            tmp = tmp->Next();
        }
        tmp->SetNext(node);
        _size++;
    }

int Socket(int domain, int type, int protocol){
    int res = socket(domain, type, protocol);
    if (res == -1){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    return res;
}
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int rez = bind(sockfd, addr, addrlen);
    if(rez == -1){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}
void Listen(int sockfd, int backlog){
    int res = listen(sockfd, backlog);
    if (res == -1){
        perror("listen failure");
        exit(EXIT_FAILURE);
    }
}
int Accept(int sockfd, struct sockaddr * addr, socklen_t *addrlen){
    int res = accept(sockfd, addr, addrlen);
    if(res == -1){
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    return res;
}
std::string Read(int client_sock) {
    ssize_t nread;
    const size_t max_buf = 256;
    char buf[max_buf];
    nread = read(client_sock, buf, max_buf); //read возвращает количество принятых данных в байтах
    if (nread == -1){
        perror("read failed");
        return "/e/";
    }
    if (nread == 0){
        printf("Your partner has left the chat\n");
        return "/q/";
    }
    std::string tmp;
    for (int i = 0; i < nread; i++) {
        tmp.push_back(buf[i]);
    }
    return tmp;
}

void NetModule::disconnect(int id) {
    for (auto it: _clients) { // закрытие сокета по указанному id
        if(it.id == id){
            close(it.client_socket);
            break;
        }
    }
    for (auto  it: _rooms) { // перенастройка комнаты
        if (it.ID1 == id){
            it.is_full = false;
            it.ID1 = 0;
            return;
        }
        else if(it.ID2 == id){
            it.is_full = false;
            it.ID2 = 0;
            return;
        }
    }
}

NetModule::NetModule(int port) {
    _sock = Socket(AF_INET, SOCK_STREAM, 0);
    _serv = {0, 0, {0}, {0, 0, 0, 0}};
    _serv.sin_family = AF_INET;
    _serv.sin_port = htons(port);
    _port = port;
    Bind(_sock, reinterpret_cast<const sockaddr *>(&_serv), sizeof _serv);


    //Создание пула потоков
    if (THREAD_COUNT == 0) THREAD_COUNT = 1;
    for (size_t i = 0; i < THREAD_COUNT; ++i) {
        _thr_pool.emplace_back(&NetModule::thread_function, this); //TO_DO
    }

    cout << S_TAG << " Port: " << _port << "; Waiting for connections...\n";
    std::thread main(&NetModule::run, this);
    main.detach();
}

void NetModule::run() {
    while (is_on) {
        Listen(_sock, BACKLOG);
        socklen_t adrlen = sizeof _serv;
        int c0 = Accept(_sock, reinterpret_cast<sockaddr *>(&_serv), &adrlen); //новый сокет для клиента
        _my_queue.add(new Node(c0));
    }
}

void NetModule::chat(int client_sock){
    srand(client_sock);
    int ID = rand() % 900 + 100; //Генерирование случайного id для клиента

    Client c = { ID, client_sock };
    _clients.push_back(c);

    cout << "Connected client with id " << ID << endl;

    std::string s = SERV_STR_0 + std::to_string(ID) + SERV_STR_1;     //Отправка сообщения о присвоении id
    write(client_sock, s.c_str(), s.size());
    while(true){
        std::string ans;
        ans = Read(client_sock);
        std::cout << ans << std::endl;
        if (ans == "test") {
            write(STDOUT_FILENO, "Success!", 8);
        } else if (ans == "/e/") {
            close(client_sock); return;
        } else if (ans == "/q/"){
            close(client_sock); return;
        } else if (ans == "0") {
            Room r = {false, ID, 0};
            _rooms.push_back(r);
            write(client_sock, SERV_STR_2.c_str(), SERV_STR_2.size());   //Отправка сообщения об ожидании партнера
        } else {
            std::string msg;
            std::cout << "Your reply: ";
            getline(std::cin, msg);
            write(client_sock, msg.c_str(), msg.size());
        }
    }
}

void NetModule::end() {
    for (auto it: _clients) {
        close(it.client_socket);
    }
    close(_sock);
}

void NetModule::thread_function() {
    while (is_on) {
    std::unique_ptr<Node> node(_my_queue.get());
        if (node) {
            chat(node->_sock);
        }
    }
}

NetModule::~NetModule() = default;
