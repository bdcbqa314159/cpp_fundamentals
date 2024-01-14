#include <iostream>
#include <string>
#include <vector>
#include <map>

const char nl = '\n';

int main()
{
    std::cout << "Activity 20: Retrieving a User's Balance from their Given Username" << nl;

    std::map<std::string, int> balances{};

    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};

    for (auto name : names)
        balances.insert(std::make_pair(name, 50));

    std::cout << "Does Donald have a balance?" << nl;
    auto position = balances.find("Donald");

    if (position == balances.end())
        std::cout << "No he does not" << nl;
    else
        std::cout << "Yes and he has: " << balances.at("Donald") << " in his account." << nl;

    return 0;
}
