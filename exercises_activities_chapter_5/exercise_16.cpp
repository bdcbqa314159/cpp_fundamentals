#include <iostream>
#include <vector>

const char nl = '\n';

int main()
{
    std::cout << "Exercise 16: Exploring Functions of Reverse Iterator" << std::endl;

    std::vector<int> container = {1, 2, 3, 4, 5};

    for (std::vector<int>::reverse_iterator rit = container.rbegin(); rit != container.rend(); ++rit)
        std::cout << *rit << nl;

    return 0;
}
