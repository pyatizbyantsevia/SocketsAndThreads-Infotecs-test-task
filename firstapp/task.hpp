#ifndef TASK_HPP
#define TASK_HPP

#include "socket-wrapper.hpp"

#include <list>
#include <iosfwd>
#include <mutex>
#include <condition_variable>

namespace pyatizbyantsev
{
    class Task
    {
    public:
        Task(int);
        void primaryProcessing(std::istream&, std::ostream&);
        void secondaryProcessing(std::ostream&);

    private:
        std::list< std::string > buffer_;
        std::mutex mtx_;
        std::condition_variable cv_;
        int socketPort_;
    };
}

#endif
