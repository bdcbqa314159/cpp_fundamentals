#include <iostream>
#include "cars.hpp"

int main()
{

    std::cout << "Organizing Functions in Namespaces" << std::endl;
    unsigned int input = 0;

    while (input != 1 && input != 2)
    {
        std::cout << "Please enter a 1 or 2 >> ";
        std::cin >> input;
    }
    std::cout << std::endl
              << "Thanks!" << std::endl;
    if (input == 1)
        LamborghiniCar::output();
    else
        PorscheCar::output();

    std::cout << "Bye" << std::endl;

    return 0;
}
