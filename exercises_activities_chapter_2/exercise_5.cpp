#include "by_value.hpp"
#include <iostream>

int main()
{
    std::cout << "Calculating Age using Pass by Value Arguments" << std::endl;
    int age = 95;
    byvalue_age_in_5_years(age);
    std::cout << "current age: " << age << std::endl;

    return 0;
}