#include "by_value.hpp"
#include <iostream>

void byvalue_age_in_5_years(int age)
{
    age += 5;
    std::cout << "the age in the function: " << age << std::endl;
    return;
}