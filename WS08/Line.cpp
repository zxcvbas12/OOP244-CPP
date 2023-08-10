/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Ji Ho Nam     July 19,2023
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Line.h"

namespace sdds
{
    //   Line::Line()
    //   {
    //       m_length = 0;
    //   }

    Line::Line(const char *lbl, int length) : LblShape(lbl)
    {
        if (length > 0)
        {
            m_length = length;
        }
    }

    void Line::getSpecs(std::istream &is)
    {
        int length;
        bool result = false;

        do
        {
            LblShape::getSpecs(is);

            is >> length;

            if (!is)
            {
                is.clear();
                is.ignore(1000, '\n');
            }
            else
            {
                is.ignore();
                m_length = length;
                result = true;
            }
        } while (!result);
    }

    void Line::draw(std::ostream &os) const
    {
        if (m_length > 0 && LblShape::label())
        {
            os << LblShape::label() << std::endl;
            os.width(m_length);
            os.fill('=');
            os << '=';
        }
    }
}