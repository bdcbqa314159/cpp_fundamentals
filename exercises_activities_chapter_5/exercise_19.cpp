#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>

const char nl = '\n';

struct UserAccount
{
    int balance{}, daysSinceRegistered{};
};

void computeAnalytics(std::map<std::string, UserAccount> &accounts)
{
    std::vector<UserAccount> newAccounts{};

    std::transform(accounts.begin(), accounts.end(), std::back_inserter(newAccounts), [](const std::pair<std::string, UserAccount> &user)
                   { return user.second; });

    auto newEnd = std::remove_if(newAccounts.begin(), newAccounts.end(), [](const UserAccount &account)
                                 { return account.daysSinceRegistered > 15; });

    newAccounts.erase(newEnd, newAccounts.end());

    std::sort(newAccounts.begin(), newAccounts.end(), [](const UserAccount &lhs, const UserAccount &rhs)
              { return lhs.balance > rhs.balance; });

    for (const UserAccount &user : newAccounts)
        std::cout << user.balance << nl;

    return;
}

int main()
{
    std::cout << "Exercise 19: Customer Analytics" << std::endl;

    std::map<std::string, UserAccount> users = {
        {"Alice", UserAccount{500, 15}},
        {"Bob", UserAccount{1000, 50}},
        {"Charlie", UserAccount{600, 17}},
        {"Donald", UserAccount{1500, 4}}};
    computeAnalytics(users);
    return 0;
}
