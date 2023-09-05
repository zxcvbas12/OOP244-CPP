/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : Jun 18. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds
{
    class Mark
    {
        int m_value;

    public:
        Mark();
        Mark(int value);

        Mark &operator+=(int value);
        Mark &operator=(int value);
        operator int() const;
        operator double() const;
        operator char() const;
    };

    int operator+=(int &value, const Mark &mark);

}
#endif