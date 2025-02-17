#include "server.h"

Server::Server(int port): port(port), server_fd(0) {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        cerr << "Cannot create Socket. Operation Failed" << endl;
        exit(EXIT_FAILURE);
    }

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (sockaddr*)&address, sizeof(address)) < 0) {
        cerr << "Bind Failed. Operation Failed" << endl;
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        cerr << "Cannot listen. Operation Failed" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Server has started listening on port " << port << endl;

}

void Server::start() {
    sockaddr_in client_addr{};
    socklen_t addr_len = sizeof(client_addr);
    int new_socket = accept(server_fd, (sockaddr*)&client_addr, &addr_len);

    if (new_socket < 0) {
        cerr << "Could not accept connection from client" << endl;
        return;
    }

    char buffer[1024] = {0};
    read(new_socket, buffer, sizeof(buffer));
    cout << "Receivedd: " << buffer << endl;
    close(new_socket);
}


Server::~Server() {
    close(server_fd);
}