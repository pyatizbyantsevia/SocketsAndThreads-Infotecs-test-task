#include "socket-wrapper.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        std::cout << "No port provided" << '\n';
        return 1;
    }
    while (true)
    {
        MySocket mys(12345);
        mys.receive();
    }
}
