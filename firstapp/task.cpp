#include "task.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

void pyatizbyantsev::Task::primaryProcessing(std::istream& in)
{
    while (true)
    {
        std::string userString;
        std::getline(in, userString, '\n');
        
        std::for_each(userString.begin(), userString.end(), [](const char &i) 
        {
            if (!std::isdigit(i))
            {
                throw std::invalid_argument("Not digital are not allowed in arguments");
            }
        });

        if (!in || userString.size() > 64)
        {
            throw std::invalid_argument("Input error");
        }

        std::sort(userString.begin(), userString.end(), std::greater<char>());

        std::string formated;
        for (auto i = userString.begin(); i != userString.end(); i++)
        {
            std::string tmp;
            tmp += *i;
            if (std::stoi(tmp) % 2 == 0)
            {
                formated += "KB";
            }
            else
            {
                formated += *i;
            }
        }

        std::unique_lock< std::mutex > ulm(mtx);
        buffer.push_back(std::string(formated.begin(), formated.end()));
        cv.notify_one();
    }
}

void pyatizbyantsev::Task::secondaryProcessing(std::ostream& out)
{
    int sum = 0;
    while (true)
    {
        std::unique_lock< std::mutex > ulm(mtx);
        cv.wait(ulm, [this] { return !this->buffer.empty(); });
        std::copy(buffer.begin(), buffer.end(), std::ostream_iterator< std::string >(out, " "));
        out << '\n';
        buffer.clear();
    }
}
