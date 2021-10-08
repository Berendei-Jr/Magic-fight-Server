// Copyright 2021 Vedeneev Andrey <vedvedved2003@gmail.com>

#ifndef INCLUDE_NETMODULE_HPP_
#define INCLUDE_NETMODULE_HPP_

#define BACKLOG 10 //максимальное количество обслуживаемых клиентов

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <cstring>
#include <memory>

int Socket(int domain, int type, int protocol);
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
void Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr * addr, socklen_t *addrlen);

struct Client;
struct Room;
struct Node;
struct MyQueue {
    std::unique_ptr<Node> _first;
    size_t _size;
    MyQueue();
    Node* get();
    void add(Node* node);
};

class NetModule {
    int _sock;
    int _port;
    struct sockaddr_in _serv{};
    std::vector<Client> _clients;
    std::vector<Room> _rooms;
    std::vector<std::thread> _thr_pool;
    MyQueue _my_queue;
public:
    explicit NetModule(int port);
    void end();
    ~NetModule();
    void chat(int client_sock);
    void run();
    void disconnect(int id);
    void thread_function();
};

#endif //INCLUDE_NETMODULE_HPP_
