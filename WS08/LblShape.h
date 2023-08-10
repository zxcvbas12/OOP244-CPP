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
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include "Shape.h"

namespace sdds
{
    class LblShape : public Shape
    {
        char *m_label{nullptr};

    protected:
        const char *label() const;

    public:
        LblShape() {}
        LblShape(const char *chr);
        virtual ~LblShape();

        LblShape(const LblShape &src) = delete;
        LblShape &operator=(const LblShape &src) = delete;

        void getSpecs(std::istream &is);
    };
}
#endif