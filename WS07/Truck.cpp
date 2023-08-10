/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : Jul 12. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Truck.h"

namespace sdds
{
    /* Truck::Truck(const char *plate, int year, double truckCapacity, const char *address)
     {
         setPlate(plate);
         setBuilt(year);
         moveTo(address);
         currentCargo = 0;
         capacity = truckCapacity;
     }*/

    Truck::Truck(const char *plate, int year, double truckCapacity, const char *address)
        : MotorVehicle(plate, year), capacity(truckCapacity), currentCargo(0)
    {
        moveTo(address);
    }

    bool Truck::addCargo(double cargo)
    {
        bool result = false;
        if (currentCargo != capacity)
        {
            currentCargo += cargo;
            if (currentCargo > capacity)
            {
                currentCargo = capacity;
            }
            result = true;
        }

        return result;
    }

    bool Truck::unloadCargo()
    {
        bool result = false;

        if (currentCargo != 0)
        {
            currentCargo = 0;
            result = true;
        }

        return result;
    }

    std::ostream &Truck::write(std::ostream &os) const
    {
        MotorVehicle::write(os);
        os << " | " << currentCargo << "/" << capacity;

        return os;
    }

    std::istream &Truck::read(std::istream &in)
    {
        MotorVehicle::read(in);
        std::cout << "Capacity: ";
        in >> capacity;
        std::cout << "Cargo: ";
        in >> currentCargo;
        return in;
    }

    std::ostream &operator<<(std::ostream &os, const Truck &truck)
    {
        return truck.write(os);
    }

    std::istream &operator>>(std::istream &in, Truck &truck)
    {
        return truck.read(in);
    }

}