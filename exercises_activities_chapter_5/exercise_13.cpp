#include <iostream>
#include <variant>
#include <string>

const char nl = '\n';

int main()
{
    std::cout << "Exercise 13: Using Variant in the Program" << std::endl;
    std::variant<std::string, int> value = 42;

    std::cout << std::get<1>(value) << nl;
    std::cout << std::get<int>(value) << nl;

    return 0;
}
