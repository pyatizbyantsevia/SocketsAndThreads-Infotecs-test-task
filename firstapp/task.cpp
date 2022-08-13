#include "task.hpp"

#include "utils.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

void pyatizbyantsev::Task::primaryProcessing(std::istream& in, std::ostream& err)
{
    while (true)
    {
        std::string userString;
        std::getline(in, userString, '\n');
        
        if (!in)
        {
            throw std::runtime_error("Input error");
        }

        if (pyatizbyantsev::hasExtraChar(userString))
        {
            err << "Not digital are not allowed in arguments" << '\n';
            continue;
        }

        if (userString.size() > 64)
        {
            err << "The string size must be less than 64" << '\n';
            continue;
        }

        std::sort(userString.begin(), userString.end(), std::greater<char>());

        userString = pyatizbyantsev::formatString(userString);

        std::unique_lock< std::mutex > ulm(mtx);
        buffer.push_back(userString);
        cv.notify_one();
    }
}

void pyatizbyantsev::Task::secondaryProcessing(std::ostream& out)
{
    while (true)
    {
        std::unique_lock< std::mutex > ulm(mtx);
        cv.wait(ulm, [this] { return !this->buffer.empty(); });
        
        std::copy(buffer.begin(), buffer.end(), std::ostream_iterator< std::string >(out, " "));
        out << '\n';
        buffer.clear();
    }
}
