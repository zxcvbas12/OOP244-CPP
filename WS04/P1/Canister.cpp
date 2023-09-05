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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h" // using strLen, strCpy and strCmp
#include "Canister.h"
using namespace std;

const double PI = 3.14159265;

namespace sdds
{
    void Canister::setToDefault()
    {
        m_contentName = nullptr;
        m_diameter = 10.0;
        m_height = 13.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    bool Canister::isEmpty() const
    {
        return m_contentVolume < 0.00001;
    }

    bool Canister::hasSameContent(const Canister &C) const
    {
        return (m_contentName != nullptr && C.m_contentName != nullptr) && (strCmp(m_contentName, C.m_contentName) == 0);
    }

    void Canister::setName(const char *Cstr)
    {
        if (Cstr != nullptr && m_usable)
        {
            delete[] m_contentName;
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
    }

    Canister::Canister()
    {
        setToDefault();
    }

    Canister::Canister(const char *contentName)
    {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter, const char *contentName)
    {
        setToDefault();
        if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0)
        {
            m_height = height;
            m_diameter = diameter;
            setName(contentName);
        }
        else
        {
            m_usable = false;
        }
    }

    Canister::~Canister()
    {
        delete[] m_contentName;
    }

    void Canister::clear()
    {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    double Canister::capacity() const
    {
        double capacity = PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
        return capacity;
    }

    double Canister::volume() const
    {
        return m_contentVolume;
    }

    Canister &Canister::setContent(const char *contentName)
    {
        if (contentName == nullptr)
        {
            m_usable = false;
        }
        else if (isEmpty())
        {
            setName(contentName);
        }
        else if (!hasSameContent(contentName))
        {
            m_usable = false;
        }
        return *this;
    }

    Canister &Canister::pour(double quantity)
    {
        if (m_usable && quantity > 0 && (quantity + volume()) <= capacity())
        {
            m_contentVolume += quantity;
        }
        else
        {
            m_usable = false;
        }
        return *this;
    }

    Canister &Canister::pour(Canister &C)
    {
        setContent(C.m_contentName);
        if (C.volume() > (capacity() - volume()))
        {
            C.m_contentVolume -= (capacity() - volume());
            m_contentVolume = capacity();
        }
        else
        {
            pour(C.volume());
            C.m_contentVolume = 0.0;
        }
        return *this;
    }

    std::ostream &Canister::display() const
    {
        cout.width(7);
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << capacity() << "cc (";
        cout << m_height << "x" << m_diameter << ") Canister";
        if (!m_usable)
        {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr)
        {
            cout << " of " << setw(7) << volume() << "cc   " << m_contentName;
        }
        return cout;
    }
}