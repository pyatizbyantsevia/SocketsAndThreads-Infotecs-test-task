#include "task.hpp"

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void pyatizbyantsev::Task::primaryProcessing(std::istream& in)
{
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
}

void pyatizbyantsev::Task::secondaryProcessing(std::ostream& out)
{
    std::copy(userString.begin(), userString.end(), std::ostream_iterator< char >(out, " "));
}
