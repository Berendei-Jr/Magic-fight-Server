// Copyright 2021 Vedeneev Andrey <vedvedved2003@gmail.com>

#include "Server.hpp"
std::string S_TAG = "[SERVER] ";

std::string SERV_STR_0 = S_TAG + "The system has assigned you ID: ";
std::string SERV_STR_1 = "\n" + S_TAG + "Enter your partner's ID. If you want to create a room enter '0': ";
std::string SERV_STR_2 = S_TAG + "Waiting for your partner...\n";

using std::cout; using std::endl; using std::cerr;

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

void Server::disconnect(int id) {
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

Server::Server() {}

void Server::init(int port) {
    _sock = Socket(AF_INET, SOCK_STREAM, 0);
    _serv = {0, 0, {0}, {0, 0, 0, 0}};
    _serv.sin_family = AF_INET;
    _serv.sin_port = htons(port);
    _port = port;
    Bind(_sock, reinterpret_cast<const sockaddr *>(&_serv), sizeof _serv);
}

void Server::act(int client_sock){
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

void Server::run() {
    cout << S_TAG << " Port: " << _port << "; Waiting for connections...\n";
    for (int i = 0; i < BACKLOG; ++i) {
        Listen(_sock, BACKLOG);
        socklen_t adrlen = sizeof _serv;
        int c0;
        c0 = Accept(_sock, reinterpret_cast<sockaddr *>(&_serv), &adrlen); //новый сокет для клиента
        _thr.emplace_back(&Server::act, this, c0);
        _thr.back().detach();
    }
}

void Server::end() {
    for (auto it: _clients) {
        close(it.client_socket);
    }
    close(_sock);
}

Server::~Server() = default;
