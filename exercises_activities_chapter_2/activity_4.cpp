#include <iostream>

int sum(int, int);
int &get_max_between_two_arrays(std::array<int, 10> &, std::array<int, 10> &, int);

int main()
{

    std::cout << "Using Pass by Reference and Pass by Value" << std::endl;

    return 0;
}

int sum(int a, int b)
{
    return a + b;
}

int &get_max_between_two_arrays(std::array<int, 10> &array1, std::array<int, 10> &array2, int index)
{

    if (array1[index] == array2[index])
        return array1[index];

    else if (array1[index] < array2[index])
        return array2[index];

    else
        return array1[index];
}