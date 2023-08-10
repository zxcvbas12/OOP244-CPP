#ifndef TRUCK_H
#define TRUCK_H
#include "MotorVehicle.h"

namespace sdds
{
    class Truck : public MotorVehicle
    {
    private:
        double capacity;
        double current_cargo_load;

    public:
        Truck(const char *num, int year, double cap, const char *add);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &in);
    };

    std::ostream &operator<<(std::ostream &os, const Truck &truck);
    std::istream &operator>>(std::istream &is, Truck &truck);

}

#endif