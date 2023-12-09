#include <iostream>
#include <array>
#include <cmath>

double distance(const double &, const double &);
double distance(const int &, const int &);
double distance(const std::array<double, 3> &x, const std::array<double, 3> &y = {0, 0, 0});
double circumference(const double &);

int main()
{

    std::cout << "Writing a Math Library for a 3D Game" << std::endl;
    std::cout << "distance between doubles:" << std::endl;
    std::cout << distance(1.3, 4.5) << std::endl;
    std::cout << "distance between ints:" << std::endl;
    std::cout << distance(1, 4) << std::endl;
    std::cout << "circumference of a cercle with radius 2" << std::endl;
    std::cout << circumference(2.) << std::endl;

    std::array<const std::array<double, 3>, 5> points = {{{0, 0, 0},
                                                          {1, 0, 0},
                                                          {1, 1, 0},
                                                          {0, 1, 0},
                                                          {0, 1, 1}}};

    double final_distance{};
    for (int i = 1; i < 5; i++)
    {
        final_distance += distance(points[i - 1], points[i]);
    }
    std::cout << "final distance: " << final_distance << std::endl;

    return 0;
}

double distance(const double &x, const double &y)
{
    return std::abs(x - y);
}

double distance(const int &x, const int &y)
{
    return std::abs(x - y);
}

double distance(const std::array<double, 3> &x, const std::array<double, 3> &y)
{
    double result{};
    for (int i = 0; i < 3; i++)
    {
        result += std::pow(x[i] - y[i], 2);
    }
    return std::sqrt(result);
}

double circumference(const double &r)
{
    return 2 * r * M_PI;
}