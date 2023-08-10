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
#include "Rectangle.h"
#include "Utils.h"
#include <cstring>

namespace sdds
{
    //  Rectangle::Rectangle()
    //   {
    //       m_height = 0;
    //       m_width = 0;
    //   }

    Rectangle::Rectangle(const char *lbl, int width, int height) : LblShape(lbl)
    {
        int wid = strlen(LblShape::label()) + 2;

        if (width > wid && height > 3)
        {
            m_width = width;
            m_height = height;
        }
    }

    void Rectangle::getSpecs(std::istream &is)
    {
        int width;
        int height;
        char _comma;
        bool result = false;

        do
        {

            LblShape::getSpecs(is);
            is >> width >> _comma >> height;

            if (!is)
            {
                is.clear();
                is.ignore(1000, '\n');
            }
            else
            {
                is.ignore();
                m_width = width;
                m_height = height;
                result = true;
            }
        } while (!result);
    }

    void Rectangle::draw(std::ostream &os) const
    {
        if (m_width > 0 && m_height > 0)
        {
            os << '+';
            for (int i = 0; i < m_width - 2; ++i)
            {
                os << "-";
            }
            os << "+" << std::endl;

            os << '|';
            os.width(m_width - 2);
            os.fill(' ');
            os << std::left << LblShape::label() << '|' << std::endl;

            for (int i = 0; i < (m_height - 3); i++)
            {
                os << '|';
                os.width(m_width - 2);
                os.fill(' ');
                os << ' ' << '|' << std::endl;
            }

            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+';
        }
    }
}