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
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds
{
    class Line : public LblShape
    {
        int m_length{0};

    public:
        Line() {}
        Line(const char *lbl, int length);
        virtual ~Line() {}

        void getSpecs(std::istream &is);
        void draw(std::ostream &os) const;
    };

}
#endif