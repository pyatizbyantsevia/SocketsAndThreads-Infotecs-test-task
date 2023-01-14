#ifndef SOCKET_WRAPPER_HPP
#define SOCKET_WRAPPER_HPP

#include <netdb.h>

class MySocket
{
public: 
    MySocket(int);
    void receive();

private:
    int client, server;
    struct sockaddr_in server_address;
};

#endif
