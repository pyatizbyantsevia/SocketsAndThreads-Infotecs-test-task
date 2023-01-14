#include "socket-wrapper.hpp"

#include <iostream>
#include <cstring>
#include <arpa/inet.h>

MySocket::MySocket(int port)
{
    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0)
    {
        throw std::runtime_error("Establishing socket error");
    }

    server_address.sin_port = htons(port);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htons(INADDR_ANY);
    
    int ret = bind(client, reinterpret_cast<struct sockaddr*>(&server_address), sizeof(server_address));
    if (ret < 0)
    {
        throw std::runtime_error("Binding error");
    }

    socklen_t size = sizeof(server_address);
    std::cout << "Listening client" << '\n';
    listen(client, 1);
    server = accept(client, reinterpret_cast<struct sockaddr*>(&server_address), &size);
    if (server < 0)
    {
        throw std::runtime_error("Can't accept client");
    }
}

void MySocket::receive()
{
    char buffer[256];
    recv(server, buffer, 256, 0);
    std::cout << buffer;
}
