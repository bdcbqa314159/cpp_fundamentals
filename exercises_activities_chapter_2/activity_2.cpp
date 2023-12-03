#include <iostream>

int main()
{

    std::cout << "Defining a Bi-Dimensional Array and Initializing Its Elements" << std::endl;
    int array[3][3] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = i + j;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "array[" << i << "," << j << "] = " << array[i][j] << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}