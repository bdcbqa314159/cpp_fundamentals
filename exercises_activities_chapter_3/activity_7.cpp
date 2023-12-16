#include <iostream>

class Coordinates
{

private:
    float latitude = 0, longitude = 0;

public:
    void set_latitude(const float &x)
    {
        this->latitude = x;
    }
    void set_longitude(const float &y)
    {
        this->longitude = y;
    }

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

    my_coordinates.set_latitude(3.4);
    my_coordinates.set_longitude(5.4);

    std::cout << "my_cooridnates after setting stuff:" << std::endl;
    std::cout << my_coordinates.get_latitude() << std::endl;
    std::cout << my_coordinates.get_longitude() << std::endl;

    return 0;
}
