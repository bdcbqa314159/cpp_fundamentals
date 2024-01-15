#include <iostream>
#include <vector>

const char nl = '\n';

int main()
{
    std::cout << "Exercise 15: Exploring Iterator" << std::endl;

    std::vector<int> container = {1, 2, 3, 4, 5};
    std::vector<int>::iterator it = container.begin();

    std::cout << *it << nl;
    it++;
    std::cout << *it << nl;

    std::cout << it[2] << nl;
    it--;
    std::cout << *it << nl;

    it += 4;
    std::cout << *it << nl;

    it++;

    std::cout << "it is after the last element? " << (it == container.end()) << nl;

    return 0;
}
