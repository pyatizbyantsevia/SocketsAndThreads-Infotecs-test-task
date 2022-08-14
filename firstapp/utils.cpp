#include "utils.hpp"

#include <string>
#include <algorithm>
#include <iostream>

bool pyatizbyantsev::hasExtraChar(const std::string& src)
{
    for (const auto& i : src) 
    {
        if (!std::isdigit(i))
        {
            return true;
        }
    }
    return false;
}

std::string pyatizbyantsev::formatString(const std::string& src)
{
    std::string formatted;
    for (const auto& i : src)
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

int pyatizbyantsev::sumOfDigital(const std::string& src)
{
    int sum = 0;
    for (const auto& i : src)
    {
        if (std::isdigit(i))
        {
            std::string tmp;
            tmp += i;
            sum += std::stoi(tmp);
        }
    }
    return sum;
}
