/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : Jun 07. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds
{
    class Canister
    {
        char *m_contentName;
        double m_diameter;      // in centimeters
        double m_height;        // in centimeters
        double m_contentVolume; // in CCs
        bool m_usable;

        void setToDefault();
        void setName(const char *Cstr);
        bool isEmpty() const;
        bool hasSameContent(const Canister &C) const;

    public:
        Canister();
        Canister(const char *contentName);
        Canister(double height, double diameter,
                 const char *contentName = nullptr);
        ~Canister();
        Canister &setContent(const char *contentName);
        Canister &pour(double quantity);
        Canister &pour(Canister &);
        double volume() const;
        std::ostream &display() const;
        double capacity() const;
        void clear();
    };
}

#endif // !SDDS_BOX_H
