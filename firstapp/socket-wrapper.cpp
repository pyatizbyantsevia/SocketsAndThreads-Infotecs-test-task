#include "socket-wrapper.hpp"

#include <iostream>
#include <cstring>
#include <arpa/inet.h>

pyatizbyantsev::SocketWrapper::SocketWrapper(int port)
{
    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0)
    {
        throw std::runtime_error("Establishing socket error");
    }

    server_address.sin_port = htons(port);
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr); /* @todo refactor hardcode */

    int ret = connect(client, reinterpret_cast<const struct sockaddr*>(&server_address), sizeof(server_address));
    if (ret < 0)
    {
        throw std::runtime_error("Error while connecting");
    }
}

void pyatizbyantsev::SocketWrapper::SocketWrapper::sendSum(int x)
{
    char buffer[256];
    strcpy(buffer, "Server connected\n");
    send(client, buffer, 256, 0);
}
