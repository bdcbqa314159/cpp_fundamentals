#include <iostream>
#include <string>

struct EUBankAccount
{
    std::string IBAN;
    int amount;
};

struct UKBankAccount
{
    std::string sortNumber, accountNumber;
    int amount;
};

template <typename BankAccount>
int getMaxAccount(const BankAccount &acc1, const BankAccount &acc2)
{
    if (acc1.amount < acc2.amount)
        return acc2.amount;
    else
        return acc1.amount;
}

int main()
{
    std::cout << "Exercise 11: Finding the Bank Account of the User with the Highest Balance" << std::endl;

    EUBankAccount acc1{"IBAN1", 1000}, acc2{"IBAN2", 1500};

    std::cout << "The biggest account in eu has: " << getMaxAccount(acc1, acc2) << std::endl;

    UKBankAccount acc3{"sort1", "acc1", 3000}, acc4{"sort2", "acc2", 400};

    std::cout << "The biggest account in gbp has: " << getMaxAccount(acc3, acc4) << std::endl;

    return 0;
}
