#include "fibonacci.hpp"
#include <iostream>

const int POSITION = 10;
const int ALREADY_COMPUTED = 3;

void print_tenth_fibonacci()
{
    int n_1 = 0;
    int n_2 = 1;
    int current = n_1 + n_2;

    // std::cout << n_1 << std::endl;
    // std::cout << n_2 << std::endl;
    // std::cout << current << std::endl;

    for (int i = ALREADY_COMPUTED; i < POSITION; i++)
    {
        n_1 = n_2;
        n_2 = current;
        current = n_1 + n_2;
        std::cout << current << std::endl;
    }

    std::cout << "Final answer: " << current << std::endl;

    return;
}