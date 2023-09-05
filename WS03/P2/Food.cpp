/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : Jun 02. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds
{

    void Food::setName(const char *name)
    {
        if (name != nullptr)
        {
            strnCpy(foodName, name, 20);
            foodName[20] = '\0';
        }
    }

    void Food::setEmpty()
    {
        foodName[0] = '\0';
        cal = 0;
    }

    void Food::set(const char *name, int cal, int mealNum)
    {
        if (cal < 0 || name == nullptr)
        {
            setEmpty();
        }
        else
        {
            setName(name);
            cal = cal;
            meal = mealNum;
        }
    }

    int Food::calories() const
    {
        return cal;
    }

    int Food::mealtype() const
    {
        double taxed = 0.0;

        if (meal)
        {
            taxed = cal * rate;
        }
        return taxed;
    }

    bool Food::isValid() const
    {
        bool ok = false;
        if (foodName[0] != '\0')
        {
            ok = true;
        }

        return ok;
    }

    void Food::display() const
    {
        if (isValid())
        {
            cout << "| "
                 << left << setw(20) << setfill('.') << foodName
                 << " | "
                 << right << setw(7) << setfill(' ') << fixed << setprecision(2) << cal
                 << " | "
                 << (meal ? "Yes" : "No ")
                 << " |" << endl;
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }
}