#include <iostream>

class Coordinates
{

private:
    float latitude, longitude;

public:
    Coordinates()
    {
        latitude = 0;
        longitude = 0;
    }

    Coordinates(float x, float y) : latitude(x), longitude(y) {}

    float get_latitude()
    {
        return latitude;
    }

    float get_longitude()
    {
        return longitude;
    }
};

int main()
{
    Coordinates my_coordinates;

    std::cout << "my_cooridnates at the beginning:" << std::endl;
    std::cout << my_coordinates.get_latitude() << std::endl;
    std::cout << my_coordinates.get_longitude() << std::endl;

    Coordinates my_coordinates_set(4.3, 3.5);

    std::cout << "my_cooridnates after setting stuff:" << std::endl;
    std::cout << my_coordinates_set.get_latitude() << std::endl;
    std::cout << my_coordinates_set.get_longitude() << std::endl;

    return 0;
}
