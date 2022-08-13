#include "utils.hpp"

#include <string>
#include <algorithm>

bool pyatizbyantsev::hasExtraChar(const std::string& src)
{
    for (char i : src) 
    {
        if (!std::isdigit(i))
        {
            return 1;
        }
    }
    return 0;
}

std::string pyatizbyantsev::formatString(const std::string& src)
{
    std::string formatted;
    for (char i : src)
    {
        std::string tmp;
        tmp += i;
        if (std::stoi(tmp) % 2 == 0)
        {
            formatted += "KB";
        }
        else
        {
            formatted += i;
        }
    }
    return formatted;
}