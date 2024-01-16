#include <iostream>
#include <string>

const char nl = '\n';

class DataScienceDev
{
public:
    DataScienceDev()
    {
        std::cout << "Welcome to the data science dev community" << nl;
    }
};

class FutureCppDev
{

public:
    FutureCppDev()
    {
        std::cout << "Welcome to the future of c++ dev community" << nl;
    }
};

class Student : public DataScienceDev, public FutureCppDev
{
public:
    Student()
    {
        std::cout << "A student is a datascience dev and a future c++ dev" << nl;
    }
};

int main()
{
    std::cout << "Exercise 21: Using Multiple Inheritance to Create a \"Welcome to the Community\" Message Application" << nl;

    Student s_1;

    return 0;
}
