#include <iostream>

class Point
{
public:
    Point() : p_1(0), p_2(0) {}

    Point(double x, double y) : p_1(x), p_2(y) {}

    Point(const Point &other) : p_1(other.p_1), p_2(other.p_2) {}

    Point &operator=(const Point &other)
    {
        if (this != &other)
        {
            p_1 = other.p_1;
            p_2 = other.p_2;
        }

        return *this;
    }

    bool operator<(const Point &other)
    {
        return (p_1 < other.p_1) && (p_2 < other.p_2);
    }

private:
    double p_1 = 0, p_2 = 0;
};

int main()
{
    Point x(1, 2), y(2, 3);

    std::cout << std::boolalpha;
    std::cout << "x < y ? " << (x < y) << std::endl;

    return 0;
}
