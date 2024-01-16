#include <iostream>
#include <array>
#include <vector>

const char nl = '\n';

int main()
{
    std::cout << "Activity 19: Storing User Accounts" << std::endl;
    std::array<int, 10> accounts_1{};

    accounts_1[0] = accounts_1[accounts_1.size() - 1] = 100;
    for (size_t i = 0; i < accounts_1.size(); i++)
        std::cout << accounts_1.at(i) << nl;

    std::vector<int> accounts_2{};
    accounts_2.reserve(100);
    accounts_2.resize(10);

    for (size_t i = 0; i < accounts_2.size(); i++)
        accounts_2.at(i) = 0;

    for (size_t i = 0; i < accounts_2.size(); i++)
        std::cout << accounts_2.at(i) << nl;

    return 0;
}
