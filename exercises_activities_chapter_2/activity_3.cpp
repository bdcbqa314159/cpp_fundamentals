#include "by_reference.hpp"
#include <iostream>

int main()
{

    std::cout << "Checking Voting Eligibility" << std::endl;

    int input{};

    std::cout << "Enter a your age >> ";
    std::cin >> input;

    byreference_age_in_5_years_voting(input);

    return 0;
}