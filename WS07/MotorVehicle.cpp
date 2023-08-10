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
#include "MotorVehicle.h"

namespace sdds
{
    MotorVehicle::MotorVehicle(const char *plate, int year)
    {
        setPlate(plate);
        setAddress("Factory");
        setBuilt(year);
    }

    void MotorVehicle::setPlate(const char *plate)
    {
        strnCpy(m_plateNum, plate, 8);
        m_plateNum[8] = '\0';
    }

    void MotorVehicle::setAddress(const char *address)
    {
        strnCpy(m_address, "Factory", 63);
        m_address[63] = '\0';
    }

    void MotorVehicle::setBuilt(int year)
    {
        m_builtYear = year;
    }

    void MotorVehicle::moveTo(const char *address)
    {
        if (strCmp(address, m_address) != 0)
        {
            std::cout << "|" << std::setw(8) << std::right << m_plateNum
                      << "| |" << std::setw(20) << std::right << m_address
                      << " ---> " << std::setw(20) << std::left << address
                      << "|" << std::endl;
            strnCpy(m_address, address, 63);
            m_address[63] = '\0';
        }
    }

    std::ostream &MotorVehicle::write(std::ostream &os) const
    {
        os << "| " << m_builtYear
           << " | " << m_plateNum
           << " | " << m_address;
        return os;
    }

    std::istream &MotorVehicle::read(std::istream &in)
    {
        std::cout << "Built year: ";
        in >> m_builtYear;
        std::cout << "License plate: ";
        in >> m_plateNum;
        std::cout << "Current location: ";
        in >> m_address;
        return in;
    }

    std::ostream &operator<<(std::ostream &os, const MotorVehicle &vehicle)
    {
        return vehicle.write(os);
    }

    std::istream &operator>>(std::istream &in, MotorVehicle &vehicle)
    {
        return vehicle.read(in);
    }
}