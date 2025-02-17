#ifndef SERVER_H
#define SERVER_H

#include "protocol.h"
#include <iostream>
#include <string>
#include <memory>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

class Server {
public:
    explicit Server(int port);
        void start();
        ~Server();
private:
    int server_id;
    int port;
    unique_ptr<Protocol> protocol;
};

#endif