#include "PrintName.hpp"
#include <iostream>

void PrintName::set_name(const std::string &name)
{
    this->name = name;
}

void PrintName::print_name()
{

    std::cout << "Hey! " << this->name << " you are welcome into the team c++!" << std::endl;
}