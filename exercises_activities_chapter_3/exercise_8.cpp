#include <iostream>
#include "printName.hpp"

int main()
{

    const std::string &name_temp = "Bernardo";

    PrintName name;

    name.set_name(name_temp);
    name.print_name();

    return 0;
}