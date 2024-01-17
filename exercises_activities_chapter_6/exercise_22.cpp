#include <iostream>
#include <string>

const char nl = '\n';

class Vehicle
{
public:
    void turnOn()
    {
        std::cout << "Vehicle: turn on" << nl;
    }
};

class Car : public Vehicle
{
public:
    virtual void turnOn()
    {
        std::cout << "Car: turn on" << nl;
    }
};

void myTurnOn(Vehicle &vehicle)
{
    std::cout << "Calling the turnOn method: " << nl;
    vehicle.turnOn();
    return;
}

int main()
{
    std::cout << "Exercise 22: Exploring the Virtual Method" << nl;
    Car car;
    myTurnOn(car);
    std::cout << "Here we did not have dynamic dispatch because virtual is not in Vehicle" << nl;

    return 0;
}
