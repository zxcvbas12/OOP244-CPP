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
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds
{
    class HtmlText : public Text
    {
        char *m_title{nullptr};

    public:
        HtmlText(const char *filename = nullptr, const char *title = nullptr);
        HtmlText(const HtmlText &src);
        HtmlText &operator=(const HtmlText &src);
        ~HtmlText();

        void write(std::ostream &os) const;
    };
}
#endif // !SDDS_HTMLTEXT_H__
