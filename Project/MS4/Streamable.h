// Final Project Milestone 4
// Periodical Publication
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ji Ho Nam         July 23.2023
/////////////////////////////////////////////////////////////////
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>

namespace sdds
{
    class Streamable
    {
    public:
        // Functions overriding this function will write into an ostream object
        virtual std::ostream &write(std::ostream &os) const = 0;

        // Functions overriding this function will read from an istream object.
        virtual std::istream &read(std::istream &is) = 0;

        // Functions overriding this function will determine if the incoming ios object is a console IO object or not
        virtual bool conIO(std::ios &io) const = 0;

        // Overloads of this method will return if the Streamable object is in a valid state or not
        virtual operator bool() const = 0;

        // Empty virtual destructor to this interface to guaranty that the descendants of the Streamable are removed from memory with no leak
        virtual ~Streamable();
    };
    // Insertion and Extraction operator overloads
    std::ostream &operator<<(std::ostream &os, const Streamable &s);
    std::istream &operator>>(std::istream &is, Streamable &s);
}

#endif // SDDS_STREAMABLE_H