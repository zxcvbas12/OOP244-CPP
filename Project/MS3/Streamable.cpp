// Final Project Milestone 3
// Periodical Publication
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ji Ho Nam         July 22.2023
/////////////////////////////////////////////////////////////////
#include "Streamable.h"
#include <iostream>

namespace sdds
{
    Streamable::~Streamable(){};

    std::ostream &operator<<(std::ostream &os, const Streamable &stream)
    {
        if (stream)
        {
            stream.write(os);
        }
        return os;
    }
    std::istream &operator>>(std::istream &is, Streamable &stream)
    {
        return (stream.read(is));
    }
}