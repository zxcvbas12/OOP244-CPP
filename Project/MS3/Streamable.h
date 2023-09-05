// Final Project Milestone 3
// Periodical Publication
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ji Ho Nam         July 22.2023
/////////////////////////////////////////////////////////////////
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
namespace sdds
{
    class Streamable
    {

    public:
        virtual std::ostream &write(std::ostream &os) const = 0;
        virtual std::istream &read(std::istream &is) = 0;
        virtual bool conIO(std::ios &io) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable();
    };
    std::ostream &operator<<(std::ostream &os, const Streamable &stream);
    std::istream &operator>>(std::istream &is, Streamable &stream);
}
#endif