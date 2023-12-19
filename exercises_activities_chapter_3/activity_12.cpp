#include <iostream>

class AddX
{

public:
    AddX() : value(0) {}
    AddX(int x) : value(x) {}
    AddX(const AddX &other) : value(other.value) {}
    AddX &operator=(const AddX &other)
    {
        if (this != &other)
        {
            value = other.value;
        }
        return *this;
    }

    int operator()(int other_value)
    {
        return this->value + other_value;
    }

private:
    int value;
};

int main()
{
    AddX my_addx(4);
    std::cout << "my current obj holds the value 4" << std::endl;
    std::cout << "we add it 9 and we have: " << my_addx(9) << std::endl;
    std::cout << "Which should be 13" << std::endl;

    return 0;
}
