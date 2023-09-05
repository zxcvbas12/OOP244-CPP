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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

namespace sdds
{
    Mark::Mark()
    {
        m_value = 0;
    }
    Mark::Mark(int value)
    {
        m_value = value;
    }

    Mark::operator int() const
    {
        int value = 0;

        if (m_value >= 0 && m_value <= 100)
        {
            value = m_value;
        }
        return value;
    }

    Mark &Mark::operator+=(int value)
    {
        if (m_value >= 0 && m_value <= 100)
        {
            m_value += value;
        }
        return *this;
    }

    Mark &Mark::operator=(int value)
    {

        m_value = value;

        return *this;
    }

    Mark::operator double() const
    {
        double result = 0.0;
        if (m_value >= 0 && m_value < 50)
        {
            result = 0.0;
        }
        else if (m_value >= 50 && m_value < 60)
        {
            result = 1.0;
        }
        else if (m_value >= 60 && m_value < 70)
        {
            result = 2.0;
        }
        else if (m_value >= 70 && m_value < 80)
        {
            result = 3.0;
        }
        else if (m_value >= 80 && m_value <= 100)
        {
            result = 4.0;
        }
        return result;
    }

    Mark::operator char() const
    {
        char result = 'X';

        if (m_value >= 0 && m_value < 50)
        {
            result = 'F';
        }
        else if (m_value >= 50 && m_value < 60)
        {
            result = 'D';
        }
        else if (m_value >= 60 && m_value < 70)
        {
            result = 'C';
        }
        else if (m_value >= 70 && m_value < 80)
        {
            result = 'B';
        }
        else if (m_value >= 80 && m_value <= 100)
        {
            result = 'A';
        }

        return result;
    }

    int operator+=(int &value, const Mark &mark)
    {
        if (mark.operator int() >= 0 && mark.operator int() <= 100)
        {
            value += mark.operator int();
        }

        return value;
    }
}