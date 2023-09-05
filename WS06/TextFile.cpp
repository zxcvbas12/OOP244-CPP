/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : Jul 09. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    Line::operator const char *() const
    {
        return (const char *)m_value;
    }
    Line &Line::operator=(const char *lineValue)
    {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }
    Line::~Line()
    {
        delete[] m_value;
    }

    void TextFile::setEmpty()
    {
        delete[] m_textLines;
        m_textLines = nullptr;

        delete[] m_filename;
        m_filename = nullptr;

        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char *fname, bool isCopy)
    {
        delete[] m_filename;
        if (isCopy)
        {
            m_filename = new char[strLen(fname) + 3];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
        else
        {
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
    }
    void TextFile::setNoOfLines()
    {
        ifstream file(m_filename);
        m_noOfLines = 0;
        char ch;

        while (file.get(ch))
        {
            if (ch == '\n')
                m_noOfLines++;
        }
        m_noOfLines++;

        if (m_noOfLines == 0)
        {
            delete[] m_filename;
            m_filename = nullptr;
            setEmpty();
        }
    }

    void TextFile::loadText()
    {
        if (m_filename != nullptr)
        {
            delete[] m_textLines;
            m_textLines = nullptr;

            ifstream file(m_filename);
            if (file.is_open())
            {
                string line;
                m_noOfLines = 0;

                while (getline(file, line))
                    m_noOfLines++;

                if (m_noOfLines > 0)
                {
                    m_textLines = new Line[m_noOfLines];

                    file.clear();
                    file.seekg(0);

                    for (unsigned int i = 0; i < m_noOfLines; i++)
                    {
                        getline(file, line);
                        m_textLines[i] = line.c_str();
                    }
                }
            }
            file.close();
        }
    }

    void TextFile::saveAs(const char *fileName) const
    {
        ofstream myFile(fileName);

        for (unsigned int i = 0; i < m_noOfLines; i++)
        {
            myFile << m_textLines[i] << endl;
        }
    }

    TextFile::TextFile(unsigned pageSize)
    {
        m_pageSize = pageSize;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    TextFile::TextFile(const char *filename, unsigned int pageSize)
    {
        m_pageSize = pageSize;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;

        if (filename != nullptr)
        {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile &src)
    {
        m_pageSize = src.m_pageSize;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;

        if (src.m_filename != nullptr)
        {
            m_filename = new char[strLen(src.m_filename) + 1];
            setFilename(src.m_filename, true);
            src.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile &TextFile::operator=(const TextFile &src)
    {
        if (this != &src)
        {
            delete[] m_textLines;
            m_textLines = nullptr;
            src.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return *this;
    }

    TextFile::~TextFile()
    {
        delete[] m_textLines;
        delete[] m_filename;
    }

    unsigned TextFile::lines() const
    {
        return m_noOfLines;
    }

    ostream &TextFile::view(ostream &ostr) const
    {
        int i;
        unsigned j, k = 0;
        if (*this)
        {
            ostr << m_filename << endl;
            for (i = 0; i < strLen(m_filename); i++)
            {
                ostr << '=';
            }
            ostr << endl;

            for (j = 0; j < m_noOfLines; j++)
            {
                ostr << m_textLines[j] << endl;
                k++;
                if (k == m_pageSize)
                {
                    ostr << "Hit ENTER to continue...";
                    string input;
                    getline(cin, input);
                    k = 0;
                }
            }
        }
        return ostr;
    }

    istream &TextFile::getFile(istream &istr)
    {
        string file, line;
        getline(istr, file);
        setFilename(file.c_str());
        loadText();

        istr.clear();

        return istr;
    }

    const char *TextFile::operator[](unsigned index) const
    {
        const char *ret = nullptr;

        if ((int)m_noOfLines > 0)
        {
            ret = m_textLines[index % (int)m_noOfLines];
        }

        return ret;
    }

    TextFile::operator bool() const
    {
        bool result = false;
        if (m_filename != nullptr && m_textLines != nullptr && m_noOfLines > 0)
        {
            result = true;
        }

        return result;
    }

    const char *TextFile::name() const
    {
        return m_filename;
    }

    ostream &operator<<(ostream &ostr, const TextFile &src)
    {
        src.view(ostr);
        return ostr;
    }

    istream &operator>>(istream &istr, TextFile &src)
    {
        src.getFile(istr);
        return istr;
    }
}