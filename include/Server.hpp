// Copyright 2021 Vedeneev Andrey <vedvedved2003@gmail.com>

#ifndef INCLUDE_SERVER_HPP_
#define INCLUDE_SERVER_HPP_

#define BACKLOG 10 //максимальное количество обслуживаемых клиентов

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <thread>
#include <cstring>

int Socket(int domain, int type, int protocol);
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
void Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr * addr, socklen_t *addrlen);

struct Client {
    int id;
    int client_socket;
};

struct Room {
    bool is_full;
    int ID1;
    int ID2;
};

class Server {
    int _sock{};
    int _port{};
    struct sockaddr_in _serv{};
    std::vector<Client> _clients;
    std::vector<Room> _rooms;
    std::vector<std::thread> _thr;
public:
    Server();
    void init(int port);
    void run();
    void end();
    ~Server();
    void act(int client_sock);
    void disconnect(int id);
};

#endif //INCLUDE_SERVER_HPP_
