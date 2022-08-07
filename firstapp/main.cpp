#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main()
{
    std::istream_iterator< char > beginstreamIterator(std::cin);
    std::istream_iterator< char > finishIstreamIterator;
    std::list< char > chars;
    std::copy_if(beginstreamIterator, finishIstreamIterator, 
                    std::back_inserter(chars), [](const char& i)
    {
        if (!std::isdigit(i))
        {
            throw std::invalid_argument("Not digital are not allowed in arguments");
        }
        return i;
    });
    if ((!std::cin && !std::cin.eof()) || chars.size() > 64)
    {
        throw std::invalid_argument("Input error");
    }
    chars.sort(std::greater<char>());
    for (int i = 0; i < chars.size(); i++)
    {
        auto current = chars.begin();
        std::advance(current, i);
        if (*current % 2 == 0)
        {
            chars.insert(current, 'K');
            chars.insert(current, 'B');
            chars.erase(current);
            i += 2;
        }
    }

    std::ostream_iterator< char > out(std::cout, " ");
    std::copy(chars.begin(), chars.end(), out);
}
