#include "client.h"

Client::Client(const string& server_ip, int server_port): server_ip(server_ip), server_port(server_port), sock(0) {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0){
        cerr << "Cannot create socket " << endl;
        exit(EXIT_FAILURE);
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip.c_str(), &server_addr.sin_addr);

    if (connect(sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0 ) {
        cerr << "Conenction Failed" << endl;
        exit(EXIT_FAILURE);
    }
}


void Client::sendMessage(const string& message) {
    send (sock, message.c_str(), message.length(), 0);
    cout << "Message sent: " << message << endl;
}

Client::~Client() {
    close(sock);
}