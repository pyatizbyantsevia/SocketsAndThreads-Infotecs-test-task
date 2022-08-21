#include "task.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

#include "utils.hpp"

pyatizbyantsev::Task::Task(int port):
    socketPort_(port)
{
}

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

        std::unique_lock< std::mutex > ulm(mtx_);
        buffer_.push_back(userString);
        cv_.notify_one();
    }
}

void pyatizbyantsev::Task::secondaryProcessing(std::ostream& out)
{
    while (true)
    {
        int sum = 0;
        std::unique_lock< std::mutex > ulm(mtx_);
        cv_.wait(ulm, [this] { return !this->buffer_.empty(); });
    
        std::copy(buffer_.begin(), buffer_.end(), std::ostream_iterator< std::string >(out, " "));
        out << '\n';

        for (const auto& i : buffer_) 
        {
            sum += sumOfDigital(i);
        }
        
        try
        {
            SocketWrapper sw(socketPort_);
            sw.sendSum(1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        buffer_.clear();
    }
}
