#ifndef SOCKET_WRAPPER_HPP
#define SOCKET_WRAPPER_HPP

#include <netdb.h>

namespace pyatizbyantsev
{
    class SocketWrapper
    {
    public:
        SocketWrapper(int);
        void sendSum(int);

    private:
        int client;
        struct sockaddr_in server_address;
    };
}

#endif
