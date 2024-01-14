#include <iostream>
#include <variant>
#include <string>
const char nl = '\n';

struct AtGate
{
    int gate{};
};

struct Taxi
{
    int lane{}, numPassengers{};
};

struct Flying
{
    double speed{};
};

struct AirPlaneVisitor
{

    void operator()(const AtGate &atGate)
    {
        std::cout << "At gate: " << atGate.gate << nl;
    }

    void operator()(const Taxi &taxi)
    {
        std::cout << "At taxi lane: " << taxi.lane << " with " << taxi.numPassengers << " passengers" << nl;
    }

    void operator()(const Flying &flying)
    {
        std::cout << "Taking off at " << flying.speed << " km/h" << nl;
    }
};

class Airplane
{

    std::variant<AtGate, Taxi, Flying> state{};

public:
    Airplane(int gate) : state(AtGate{gate}) {}

    void startTaxi(int lane, int numPassengers)
    {
        if (!std::holds_alternative<AtGate>(state))
        {
            std::cout << "Not at gate, the airplane can't taxi at lane: " << lane << nl;
            return;
        }

        std::cout << "Taxi at lane: " << lane << nl;
        state = Taxi{lane, numPassengers};
    }

    void takeOff(double speed)
    {
        if (!std::holds_alternative<Taxi>(state))
        {
            std::cout << "Not at lane, the airplane can not take off" << nl;
            return;
        }
        std::cout << "Taking off at speed: " << speed << " km/h" << nl;
        state = Flying{speed};
    }

    void currentStatus()
    {
        AirPlaneVisitor visitor{};
        std::visit(visitor, state);
        return;
    }

    // friend AirPlaneVisitor;
};

int main()
{
    std::cout << "Activity 22: Airport System Management" << nl;

    Airplane airplane(52);
    airplane.currentStatus();
    airplane.startTaxi(12, 250);
    airplane.currentStatus();
    airplane.startTaxi(13, 250);
    airplane.currentStatus();
    airplane.takeOff(800);
    airplane.currentStatus();
    airplane.takeOff(900);

    return 0;
}
