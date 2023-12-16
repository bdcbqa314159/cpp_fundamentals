#include <iostream>

class my_cooridinates
{

public:
    my_cooridinates()
    {
        std::cout << "constructor called" << std::endl;
    }

    ~my_cooridinates()
    {
        std::cout << "destructor called" << std::endl;
    }
};

int main()
{
    std::cout << "Lets work and show how constructors and destructors work" << std::endl;

    {
        my_cooridinates example;

        std::cout << "we are in the scope for the class created" << std::endl;
    }

    std::cout << "we got out from the internal scope - we should have a destructor call before this current line" << std::endl;
    std::cout << "DA END" << std::endl;

    return 0;
}