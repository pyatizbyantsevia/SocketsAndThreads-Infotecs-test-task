#ifndef TASK_HPP
#define TASK_HPP

#include <list>
#include <iosfwd>

namespace pyatizbyantsev
{
    class Task
    {
    public:
        void primaryProcessing(std::istream& in);
        void secondaryProcessing(std::ostream& out);

    private:
        std::list< char > userString;
    };
}

#endif
