/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Version 1.0
// Description
// tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Ji Ho Nam     July 26,2023
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds
{
    class Text
    {
        char *m_filename{nullptr};
        char *m_content{nullptr};
        int getFileLength() const;

    protected:
        const char &operator[](int index) const;

    public:
        Text(const char *filename = nullptr);
        Text(const Text &src);
        Text &operator=(const Text &src);

        virtual ~Text();
        void read();
        virtual void write(std::ostream &os) const;
    };

    std::ostream &operator<<(std::ostream &os, const Text &src);
}
#endif
