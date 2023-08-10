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
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include <iostream>
#include "LblShape.h"

namespace sdds
{
    class Rectangle : public LblShape
    {
        int m_width{0};
        int m_height{0};

    public:
        Rectangle() {}
        Rectangle(const char *lbl, int width, int height);
        virtual ~Rectangle() {}

        void getSpecs(std::istream &is);
        void draw(std::ostream &os) const;
    };

}
#endif