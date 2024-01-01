#include <iostream>
#include <array>

template <int CurrencyConversion>
struct Currency
{
    static const int conversionRate = CurrencyConversion;
    int d_value;
    Currency(int value) : d_value(value) {}
};

template <typename OtherCurrency, typename SourceCurrency>
OtherCurrency to(const SourceCurrency &source)
{
    float baseValue = source.d_value / float(source.conversionRate);
    int otherCurrencyValue = int(baseValue * OtherCurrency::conversionRate);
    return OtherCurrency(otherCurrencyValue);
}

template <typename Currency>
class Account
{
public:
    Account(Currency amount) : balance(amount) {}
    Currency getBalance() const { return balance; }

    template <typename OtherCurrency>
    void addToBalance(OtherCurrency amount)
    {
        balance.d_value += to<Currency>(amount).d_value;
    }

private:
    Currency balance;
};

int main()
{
    std::cout << "Activity 14: Creating a User Account to Support Multiple Currencies" << std::endl;

    using USD = Currency<100>;
    using EUR = Currency<87>;
    using GBP = Currency<78>;

    // Create an account
    Account<GBP> gbpAccount(GBP(1000));
    // Add different currencies
    std::cout << "Balance: " << gbpAccount.getBalance().d_value << " (GBP)" << std::endl;
    gbpAccount.addToBalance(EUR(100));
    std::cout << "+100 (EUR)" << std::endl;
    std::cout << "Balance: " << gbpAccount.getBalance().d_value << " (GBP)" << std::endl;
    // Or the same one
    gbpAccount.addToBalance(GBP(200));
    std::cout << "+200 (GBP)" << std::endl;
    std::cout << "Balance: " << gbpAccount.getBalance().d_value << " (GBP)" << std::endl;

    std::cout << "New balance" << std::endl;

    Account<EUR> eurAccount(EUR(2000));
    std::cout << "Balance: " << eurAccount.getBalance().d_value << " (EUR)" << std::endl;
    eurAccount.addToBalance(GBP(400));
    std::cout << "+400 (GBP)" << std::endl;
    std::cout << "Balance: " << eurAccount.getBalance().d_value << " (EUR)" << std::endl;
    eurAccount.addToBalance(USD(100));
    std::cout << "+100 (USD)" << std::endl;
    std::cout << "Balance: " << eurAccount.getBalance().d_value << " (EUR)" << std::endl;

    return 0;
}
