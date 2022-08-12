#include "task.hpp"

#include <thread>
#include <iostream>

int main()
{
    pyatizbyantsev::Task task;
    std::thread t1([&task]()
    {
        task.primaryProcessing(std::cin);
    });
    std::thread t2([&task]()
    {
        task.secondaryProcessing(std::cout);
    });
    t1.join();
    t2.join();
}
