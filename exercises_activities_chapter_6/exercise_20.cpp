#include <iostream>
#include <string>

const char nl = '\n';

class Vehicle
{
public:
    int getTankCapacity()
    {
        const int tankLiters = 10;
        std::cout << "The current tank capacity is " << tankLiters << nl;
        return tankLiters;
    }
};

class CollectorItem
{
public:
    int getValue()
    {
        return 100;
    }
};

class Ferrari250GT : protected Vehicle, public CollectorItem
{
public:
    Ferrari250GT()
    {
        std::cout << "Thanks for purchasing a Ferrari250GT with tank capaicity: " << getTankCapacity() << nl;
    }
};

int main()
{
    std::cout << "Exercise 20: Creating a Program to Illustrate Inheritance in C++" << std::endl;

    Ferrari250GT ferrari;

    std::cout << "The value of the ferrari is " << ferrari.getValue() << nl;
    std::cout << "The tank capacity is not accessible outside the class because protected: "
              << "ferrari.getTankCapacity() ->X" << nl;

    return 0;
}
