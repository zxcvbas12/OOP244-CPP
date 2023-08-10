#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

namespace sdds
{
    class MotorVehicle
    {
    private:
        char plateNum[9];
        char locate[64];
        int builtYear;

    public:
        MotorVehicle(const char *num, int year);

        void moveTo(const char *address);
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &in);
    };

    std::ostream &operator<<(std::ostream &os, const MotorVehicle &veh);
    std::istream &operator>>(std::istream &is, MotorVehicle &veh);
}

#endif