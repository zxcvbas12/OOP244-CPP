// Final Project Milestone 3
// Periodical Publication
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ji Ho Nam         July 22.2023
/////////////////////////////////////////////////////////////////
#include "Streamable.h"
#define _CRT_SECURE_NO_WARNINGS
namespace sdds
{
    // Empty virtual destructor to this interface to guaranty that the descendants of the Streamable are removed from memory with no leak
    Streamable::~Streamable(){};

    // Insertion and Extraction operator overloads
    std::ostream &operator<<(std::ostream &os, const Streamable &s)
    {
        // Object of type Streamable can be written on an ostream object only if the Streamable object is in a valid state
        if (s)
        {
            s.write(os);
        }
        return os;
    }

    std::istream &operator>>(std::istream &is, Streamable &s)
    {
        return (s.read(is));
    }
}