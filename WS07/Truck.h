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
#ifndef SDDS_Truck_H__
#define SDDS_Truck_H__
#include "MotorVehicle.h"

namespace sdds
{
    class Truck : public MotorVehicle
    {
        double capacity;
        double currentCargo;

    public:
        Truck(const char *plate, int year, double truckCapacity, const char *address);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &in);
    };
    std::ostream &operator<<(std::ostream &os, const Truck &truck);
    std::istream &operator>>(std::istream &in, Truck &truck);
}
#endif