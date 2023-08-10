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
#ifndef SDDS_MotorVehicle_H__
#define SDDS_MotorVehicle_H__
namespace sdds
{
    class MotorVehicle
    {
        char m_plateNum[9];
        char m_address[64];
        int m_builtYear;

    public:
        MotorVehicle(const char *plate, int year);
        void setPlate(const char *plate);
        void setAddress(const char *address);
        void setBuilt(int year);
        void moveTo(const char *address);

        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &in);
    };

    std::ostream &operator<<(std::ostream &os, const MotorVehicle &vehicle);
    std::istream &operator>>(std::istream &in, MotorVehicle &vehicle);
}
#endif