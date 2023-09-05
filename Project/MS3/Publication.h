// Final Project Milestone 3
// Periodical Publication
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ji Ho Nam         July 22.2023
/////////////////////////////////////////////////////////////////
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include "Streamable.h"
#include "Lib.h"
#include "Date.h"
namespace sdds
{
    class Publication : public Streamable
    {
        char *m_title;
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();
        ~Publication();

        virtual void set(int member_id);
        // Sets the membership attribute to either zero or a five-digit integer.

        void setRef(int value);
        // Sets the **libRef** attribute value

        void resetDate();
        // Sets the date to the current date of the system.

        virtual char type() const;
        // Returns the character 'P' to identify this object as a "Publication object"

        bool onLoan() const;
        // Returns true is the publication is checkout (membership is non-zero)

        Date checkoutDate() const;
        // Returns the date attribute

        bool operator==(const char *title) const;
        // Returns true if the argument title appears anywhere in the title of the
        // publication. Otherwise, it returns false; (use strstr() function in <cstring>)

        operator const char *() const;
        // Returns the title attribute

        int getRef() const;
        // Returns the libRef attirbute.
        ///////

        bool conIO(std::ios &io) const;

        std::ostream &write(std::ostream &os) const;

        std::istream &read(std::istream &istr);

        operator bool() const;

        Publication(const Publication &src);
        Publication &operator=(const Publication &src);
    };

    std::ostream &operator<<(std::ostream &os, const Publication &src);
    std::istream &operator>>(std::istream &is, Publication &src);
}
#endif