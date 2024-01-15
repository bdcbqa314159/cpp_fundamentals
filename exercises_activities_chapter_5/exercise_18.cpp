#include <iostream>
#include <iterator>

const char nl = '\n';

int main()
{
    std::cout << "Exercise 18: Printing All of the Customers' Balances" << std::endl;

    std::vector<int> balances = {10, 34, 64, 97, 56, 43, 50, 89, 32, 5};

    for (auto pos = balances.begin(); pos != balances.end(); ++pos)
        std::cout << "Balance is " << *pos << nl;

    return 0;
}
