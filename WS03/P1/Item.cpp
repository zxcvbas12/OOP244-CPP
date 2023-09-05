/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : May 31. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds
{

    void Item::setName(const char *name)
    {
        if (name != nullptr)
        {
            strnCpy(foodName, name, 20);
            foodName[20] = '\0';
        }
    }

    void Item::setEmpty()
    {
        foodName[0] = '\0';
        m_price = 0.0;
    }

    void Item::set(const char *name, double price, bool taxed)
    {
        if (price < 0.0 || name == nullptr)
        {
            setEmpty();
        }
        else
        {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    double Item::price() const
    {
        return m_price;
    }

    double Item::tax() const
    {
        double taxed = 0.0;

        if (m_taxed)
        {
            taxed = m_price * rate;
        }
        return taxed;
    }

    bool Item::isValid() const
    {
        bool ok = false;
        if (foodName[0] != '\0')
        {
            ok = true;
        }

        return ok;
    }

    void Item::display() const
    {
        if (isValid())
        {
            cout << "| "
                 << left << setw(20) << setfill('.') << foodName
                 << " | "
                 << right << setw(7) << setfill(' ') << fixed << setprecision(2) << m_price
                 << " | "
                 << (m_taxed ? "Yes" : "No ")
                 << " |" << endl;
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }
}