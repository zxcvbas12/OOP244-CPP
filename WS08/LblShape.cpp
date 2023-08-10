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
#include <iostream>
#include "LblShape.h"
#include "Utils.h"
#include <string>
#include <cstring>
using namespace std;
namespace sdds
{
    const char *LblShape::label() const
    {
        return m_label;
    }

    // LblShape::LblShape()
    // {
    //    if (m_label != nullptr)
    //    {
    //         m_label = nullptr;
    //      }
    //    }

    LblShape::LblShape(const char *chr)
    {
        if (chr && chr[0] != '\0')
        {
            m_label = new char[strlen(chr) + 1];
            strcpy(m_label, chr);
        }
    }

    LblShape::~LblShape()
    {
        if (m_label)
        {
            delete[] m_label;
            m_label = nullptr;
        }
    }

    void LblShape::getSpecs(std::istream &is)
    {
        string buf;
        getline(is, buf, ',');

        delete[] m_label;
        m_label = new char[strlen(buf.c_str()) + 1];
        strcpy(m_label, buf.c_str());
    }

}