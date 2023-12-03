#include <iostream>

int main()
{

    std::cout << "Finding the Factors of 7 between 1 and 100 Using a while Loop" << std::endl;

    unsigned count_numbers = 0, i = 1;
    while (i < 100)
    {

        if (i % 7 == 0)
        {
            std::cout << i << " is divisible by 7" << std::endl;
            count_numbers++;
        }

        i++;
    }
    std::cout << "We have " << count_numbers << " numbers which are divisible by 7 within [1,100]" << std::endl;

    return 0;
}