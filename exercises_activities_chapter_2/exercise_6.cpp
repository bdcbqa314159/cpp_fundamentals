#include "by_reference.hpp"
#include <iostream>

int main()
{
    std::cout << "Calculating Incrementation of Age using Pass by Reference" << std::endl;
    int age = 95;
    byreference_age_in_5_years(age);
    std::cout << "current age: " << age << std::endl;

    return 0;
}