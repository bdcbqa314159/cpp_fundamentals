#include <iostream>
#include <string>

const char nl = '\n';

int main()
{
    std::cout << "Exercise 12 : Demonstrating Working Mechanism of the c_str() Function" << std::endl;

    const char charString[8] = {'C', '+', '+', ' ', '1', '0', '1', '\0'};
    const char *litteralString = "C++ Fundamentals";

    std::string strString = litteralString;
    const char *charString2 = strString.c_str();

    std::cout << charString << nl;
    std::cout << charString2 << nl;

    return 0;
}
