#include <iostream>

class Apple
{

    friend class AppleTree;

    Apple() : color("red")
    {
        std::cout << "default constructor" << std::endl;
    }

    std::string color;
};

class AppleTree
{

public:
    Apple create_fruit()
    {
        Apple apple;
        return apple;
    }
};

int main()
{
    AppleTree my_tree;

    my_tree.create_fruit();

    return 0;
}
