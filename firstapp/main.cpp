#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

int main(int argc, char* argv[])
{
    std::string userString;
    std::cin >> userString;
    if(userString.size() > 64)
    {
        throw std::invalid_argument("String can't be more then 64 char");
    }
    std::for_each(userString.begin(), userString.end(), [](const char &i) 
    {
        std::cout << i << ' ';
        if (!std::isdigit(i))
        {
            throw std::invalid_argument("Not digital are not allowed in arguments");
        }
    });
    std::sort(userString.begin(), userString.end(), std::greater<char>());
    std::for_each(userString.begin(), userString.end(), [](char& i) 
    {
        char* temp = &i;
        std::cout << std::atoi(temp) << " ";
        // if (std::atoi(&i) % 2 == 0)
        // {
        //     std::cout << "Четное" << '\n';
        // }
        if (i == '2')
        {
        }
    });
}
