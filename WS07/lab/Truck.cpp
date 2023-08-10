#include <iostream>
#include "Truck.h"

namespace sdds
{
    Truck::Truck(const char *num, int year, double cap, const char *add) : MotorVehicle(num, year)
    {
        capacity = cap;
        current_cargo_load = 0.0;
        moveTo(add);
    }

    bool Truck::addCargo(double cargo)
    {
        bool ret = false;

        if (current_cargo_load != capacity)
        {
            current_cargo_load += cargo;
            if (current_cargo_load > capacity)
            {
                current_cargo_load = capacity;
            }
            ret = true;
        }
        return ret;
    }
    bool Truck::unloadCargo()
    {
        bool ret = false;

        if (current_cargo_load != 0.0)
        {
            current_cargo_load = 0.0;
            ret = true;
        }

        return ret;
    }

    std::ostream &Truck::write(std::ostream &os) const
    {
        MotorVehicle::write(os);
        os << " | " << current_cargo_load << "/" << capacity;
        return os;
    }

    std::istream &Truck::read(std::istream &in)
    {
        MotorVehicle::read(in);
        std::cout << "Capacity: ";
        in >> capacity;
        std::cout << "Cargo: ";
        in >> current_cargo_load;
        return in;
    }

    std::ostream &operator<<(std::ostream &os, const Truck &truck)
    {
        truck.write(os);
        return os;
    }

    std::istream &operator>>(std::istream &is, Truck &truck)
    {
        truck.read(is);
        return is;
    }
}