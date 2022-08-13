#ifndef TASK_HPP
#define TASK_HPP

#include <list>
#include <iosfwd>
#include <mutex>
#include <condition_variable>

namespace pyatizbyantsev
{
    class Task
    {
    public:
        void primaryProcessing(std::istream&, std::ostream&);
        void secondaryProcessing(std::ostream&);

    private:
        std::list< std::string > buffer;
        std::mutex mtx;
        std::condition_variable cv;
    };
}

#endif
