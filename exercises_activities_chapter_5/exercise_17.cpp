#include <iostream>
#include <iterator>

const char nl = '\n';

int main()
{
    std::cout << "Exercise 17: Stream Iterator" << std::endl;

    std::istream_iterator<int> it = std::istream_iterator<int>(std::cin);
    std::istream_iterator<int> end;

    for (; it != end; it++)
    {
        std::cout << "the number is " << *it << nl;
    }

    return 0;
}
