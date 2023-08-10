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
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

namespace sdds
{
    class Shape
    {
    public:
        virtual void draw(std::ostream &os) const = 0;
        virtual void getSpecs(std::istream &is) = 0;
        virtual ~Shape() {}
    };

    std::ostream &operator<<(std::ostream &os, const Shape &shape);
    std::istream &operator>>(std::istream &is, Shape &shape);
}
#endif