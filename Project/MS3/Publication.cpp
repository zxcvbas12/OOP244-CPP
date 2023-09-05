// Final Project Milestone 3
// Periodical Publication
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ji Ho Nam         July 22.2023
/////////////////////////////////////////////////////////////////
#include "Publication.h"
#include <cstring>
#include <iomanip>
namespace sdds
{
    Publication::Publication()
    {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();
    }

    Publication::~Publication()
    {
        delete[] m_title;
    }

    void Publication::set(int member_id)
    {
        m_membership = member_id;
    }

    void Publication::setRef(int value)
    {
        m_libRef = value;
    }

    void Publication::resetDate()
    {
        m_date = Date();
    }

    char Publication::type() const
    {
        return 'P';
    }

    bool Publication::onLoan() const
    {
        bool result = false;
        if (m_membership != 0)
        {
            result = true;
        }

        return result;
    }

    Date Publication::checkoutDate() const
    {
        return m_date;
    }

    bool Publication::operator==(const char *title) const
    {
        bool result = false;

        if (strstr(m_title, title) != nullptr)
        {
            result = true;
        }
        return result;
    }

    Publication::operator const char *() const
    {
        return m_title;
    }

    int Publication::getRef() const
    {
        return m_libRef;
    }
    /// @brief /////////
    /// @param p

    bool Publication::conIO(std::ios &io) const
    {
        return &io == &std::cin || &io == &std::cout;
    }

    std::ostream &Publication::write(std::ostream &os) const
    {
        if (conIO(os))
        {
            os << "| " << m_shelfId << " | " << std::setw(30) << std::left << std::setfill('.') << m_title << " | ";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << " | " << m_date << " |";
        }
        else
        {
            os << type() << "\t";
            os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << "\t" << m_date;
        }
        return os;
    }

    std::istream &Publication::read(std::istream &istr)
    {

        char title[256]{}, shelfId[SDDS_SHELF_ID_LEN + 1]{};
        int libRef = -1, membership = 0;
        Date date;

        if (m_title)
        {
            delete[] m_title;
            m_title = nullptr;
        }
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();

        if (conIO(istr))
        {
            std::cout << "Shelf No: ";
            istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1);

            if (strlen(shelfId) != SDDS_SHELF_ID_LEN)
            {
                istr.setstate(std::ios::failbit);
            }
            std::cout << "Title: ";
            istr.getline(title, 256);
            std::cout << "Date: ";
            istr >> date;
        }
        else
        {
            istr >> libRef;
            istr.ignore();
            istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
            istr.getline(title, 256, '\t');
            istr >> membership;
            istr.ignore();
            istr >> date;
        }
        if (!date)
        {
            istr.setstate(std::ios::failbit);
        }
        if (istr)
        {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            strcpy(m_shelfId, shelfId);
            m_membership = membership;
            m_date = date;
            m_libRef = libRef;
        }
        return istr;
    }

    Publication::operator bool() const
    {
        bool result = false;
        if (m_title != nullptr && m_shelfId[0] != '\0')
        {
            result = true;
        }
        return result;
    }

    Publication::Publication(const Publication &src)
    {
        *this = src;
    }

    Publication &Publication::operator=(const Publication &src)
    {
        set(src.m_membership);
        setRef(src.m_libRef);
        strcpy(m_shelfId, src.m_shelfId);
        m_date = src.m_date;
        if (m_title)
        {
            delete[] m_title;
            m_title = nullptr;
        }

        if (src.m_title != nullptr)
        {
            m_title = new char[strlen(src.m_title) + 1];
            strcpy(m_title, src.m_title);
        }
        else
        {
            m_title = nullptr;
        }
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const Publication &src)
    {
        if (src)
        {
            src.write(os);
        }
        return os;
    }
    std::istream &operator>>(std::istream &is, Publication &src)
    {
        return (src.read(is));
    }
}