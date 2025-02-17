#ifndef CLIENT_H
#define CLIENT_H

#include "protocol.h"
#include <iostream>
#include <string>
#include <memory>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

class Client {
public:
    Client(const string& server_ip, int server_port);
    void sendMessage(const string& message);
    ~Client();

private:
    int sock;
    string server_ip;
    int server_port;
    unique_ptr<Protocol> protocol;
};

#endif