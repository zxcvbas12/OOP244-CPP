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
#include "Shape.h"

namespace sdds
{
    std::ostream &operator<<(std::ostream &os, const Shape &shape)
    {
        shape.draw(os);
        return os;
    }

    std::istream &operator>>(std::istream &is, Shape &shape)
    {
        shape.getSpecs(is);
        return is;
    }
}