#include <iostream>
#include <variant>
#include <string>

const char nl = '\n';

struct Visitor
{
    void operator()(const int &value)
    {
        std::cout << "an int: " << value << nl;
    }

    void operator()(const std::string &value)
    {
        std::cout << "a string: " << value << nl;
    }
};

int main()
{
    std::cout << "Exercise 14: Visitor Variant" << std::endl;

    std::variant<std::string, int> value = 42;
    Visitor visitor{};

    std::cout << "The variant value contains: " << nl;
    std::visit(visitor, value);

    value = "another thing here";

    std::cout << "The variant value contains: " << nl;
    std::visit(visitor, value);

    return 0;
}
