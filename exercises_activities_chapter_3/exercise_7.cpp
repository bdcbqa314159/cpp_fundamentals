#include <iostream>

void squares();

int main()
{
    std::cout << "Working with Static Variables" << std::endl;
    for (int i = 0; i < 10; i++)
        squares();
    return 0;
}

void squares()
{
    static int count = 1;
    int x = count * count;

    std::cout << count << "*" << count << " = " << x << std::endl;

    count++;
}