#include <iostream>
#include <cstring>
#include <iomanip>
#include "MotorVehicle.h"

namespace sdds
{

    MotorVehicle::MotorVehicle(const char *num, int year)
    {
        strncpy(plateNum, num, 9);
        plateNum[8] = '\0';
        builtYear = year;
        strncpy(locate, "Factory", 63);
        locate[63] = '\0';
    }

    void MotorVehicle::moveTo(const char *address)
    {
        if (strcmp(plateNum, address) != 0)
        {
            std::cout << "|" << std::setw(8) << std::right << plateNum << "| |" << std::setw(20) << std::right
                      << locate << " --->" << std::setw(20) << std::left << address << "|" << std::endl;
            strncpy(locate, address, 63);
            locate[63] = '\0';
        }
    }

    std::ostream &MotorVehicle::write(std::ostream &os) const
    {
        os << "|  " << builtYear << " | " << plateNum << " | " << locate;
        return os;
    }

    std::istream &MotorVehicle::read(std::istream &in)
    {
        std::cout << "Built Year: ";
        in >> builtYear;
        std::cout << "License plate: ";
        in >> plateNum;
        std::cout << "Current location:";
        in >> locate;

        return in;
    }

    std::ostream &operator<<(std::ostream &os, const MotorVehicle &veh)
    {
        veh.write(os);
        return os;
    }
    std::istream &operator>>(std::istream &is, MotorVehicle &veh)
    {
        veh.read(is);
        return is;
    }
}
