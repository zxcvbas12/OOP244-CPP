/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P2)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : Jun 11. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Label.h"
#include "LabelMaker.h"
#include "cstring.h"
using namespace std;

namespace sdds
{
    Label::Label() : m_frame(nullptr), m_content(nullptr)
    {
        m_frame = new char[9];
        strCpy(m_frame, "+-+|+-+|");
    }

    Label::Label(const char *frameArg) : m_frame(nullptr), m_content(nullptr)
    {
        m_frame = new char[9];
        strnCpy(m_frame, frameArg, 8);
        m_frame[8] = '\0';
    }

    Label::Label(const char *frameArg, const char *content) : m_frame(nullptr), m_content(nullptr)
    {
        m_frame = new char[9];
        strnCpy(m_frame, frameArg, 8);
        m_frame[8] = '\0';

        m_content = new char[strLen(content) + 1];
        strCpy(m_content, content);
    }

    Label::~Label()
    {
        delete[] m_frame;
        delete[] m_content;
    }

    void Label::readLabel()
    {
        char buffer[71];
        std::cin.getline(buffer, 71);
        m_content = new char[strLen(buffer) + 1];
        strCpy(m_content, buffer);
    }

    std::ostream &Label::printLabel() const
    {
        std::ostream &os = cout;
        int frameLength = strLen(m_frame);
        int contentLength = m_content ? strLen(m_content) : 0;
        if (contentLength == 0)
        {
        }
        else
        {

            int width = contentLength + 2;
            if (width < frameLength)
                width = frameLength;

            os << m_frame[0];
            for (int i = 0; i < width; i++)
                os << m_frame[1];
            os << m_frame[2] << endl;

            os << m_frame[7];
            for (int i = 0; i < width; i++)
                os << " ";
            os << m_frame[3] << endl;

            os << m_frame[7] << " ";
            if (m_content)
                os << m_content;
            os << " " << m_frame[3] << endl;

            os << m_frame[7];
            for (int i = 0; i < width; i++)
                os << " ";
            os << m_frame[3] << endl;

            os << m_frame[6];
            for (int i = 0; i < width; i++)
                os << m_frame[5];
            os << m_frame[4];
        }
        return os;
    }

}