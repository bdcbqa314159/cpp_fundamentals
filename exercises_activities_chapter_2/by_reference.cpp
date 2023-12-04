#include "by_reference.hpp"
#include <iostream>

void byreference_age_in_5_years(int &age)
{
    age += 5;
    std::cout << "the age in the function: " << age << std::endl;
    return;
}

void byreference_age_in_5_years_voting(int &age)
{
    age += 5;
    std::cout << "In 5 years you will have " << age << " years" << std::endl;
    if (age >= 18)
    {
        std::cout << "Congratulations, you can vote!" << std::endl;
    }

    else
    {
        int delta = 18 - age;
        std::cout << "Sorry you need encore " << delta;
        if (delta > 1)
            std::cout << " years" << std::endl;
        else
            std::cout << " year" << std::endl;
    }

    return;
}