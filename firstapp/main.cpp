#include <iostream>
#include <thread>
#include <chrono>

#include "task.hpp"
#include "socket-wrapper.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        std::cout << "No port provided" << '\n';
        return 1;
    }

    pyatizbyantsev::Task task(12345);
    std::thread t1([&task]()
    {
        task.primaryProcessing(std::cin, std::cerr);
    });
    std::thread t2([&task]()
    {
        task.secondaryProcessing(std::cout);
    });
    t1.join();
    t2.join();
}
