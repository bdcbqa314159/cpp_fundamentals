#include <iostream>

class Height
{
    double inches = 0;

public:
    Height(double input) : inches(input) {}
    friend void print_feet(const Height &obj);
};

void print_feet(const Height &obj)
{
    std::cout << "the height in inches " << obj.inches << std::endl;
    std::cout << "the height in feet " << obj.inches * 0.083 << std::endl;
}

int main()
{
    Height my_height(83);
    print_feet(my_height);

    return 0;
}