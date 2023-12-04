#include "log.hpp"
#include <iostream>

int main()
{
    std::cout << "Calling a Function from main()" << std::endl;
    std::cout << "This is a log" << std::endl;
    log();
    return 0;
}