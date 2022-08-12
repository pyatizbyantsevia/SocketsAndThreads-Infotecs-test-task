#include "task.hpp"

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void pyatizbyantsev::Task::primaryProcessing(std::istream& in)
{
    std::cout << "START PRIMARY" << '\n';
    //while (true)
    //{
        std::cout << "1:CYCLE " << '\n';
        std::list< char > userString;
        std::istream_iterator< char > beginstreamIterator(in);
        std::istream_iterator< char > finishIstreamIterator;

        std::copy_if(beginstreamIterator, finishIstreamIterator, 
                        std::back_inserter(userString), [](const char& i)
        {
            if (!std::isdigit(i))
            {
                throw std::invalid_argument("Not digital are not allowed in arguments");
            }
            return i;
        });

        if ((!in && !in.eof()) || userString.size() > 64)
        {
            throw std::invalid_argument("Input error");
        }

        userString.sort(std::greater<char>());

        for (int i = 0; i < userString.size(); i++)
        {
            auto current = userString.begin();
            std::advance(current, i);
            if (*current % 2 == 0)
            {
                userString.insert(current, 'K');
                userString.insert(current, 'B');
                userString.erase(current);
                i += 2;
            }
        }

        std::unique_lock< std::mutex > ulm(mtx);
        buffer.push_back(std::string(userString.begin(), userString.end()));
        cv.notify_one();
    //}
}

void pyatizbyantsev::Task::secondaryProcessing(std::ostream& out)
{
    std::cout << "START SECONDARY" << '\n';
    //while (true)
    //{
        std::cout << "2:CYCLE " << '\n';
        std::unique_lock< std::mutex > ulm(mtx);
        cv.wait(ulm, [&] { return !buffer.empty(); });

        std::copy(buffer.begin(), buffer.end(), std::ostream_iterator< std::string >(out, " "));
        buffer.clear();
    //}
}
