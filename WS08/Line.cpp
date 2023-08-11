#include <iostream>
#include <cstring>
#include "Line.h"

namespace sdds
{
    Line::Line()
    {
        m_length = 0;
    }

    Line::Line(const char *chr, int length) : LblShape(chr)
    {
        if (length > 0)
        {
            m_length = length;
        }
    }

    void Line::getSpecs(std::istream &is)
    {
        int length;
        bool ret = true;
        do
        {
            LblShape::getSpecs(is);
            is >> m_length;

            if (!is)
            {
                is.clear();
                is.ignore('\n');
            }
            else
            {
                is.ignore();
                m_length = length;
                ret = true;
            }
        } while (!ret);
    }

    void Line::draw(std::ostream &os) const
    {
        if (m_length > 0 && label())
        {
            os << label() << std::endl;

            for (int i = 0; i < m_length; i++)
            {
                os << "=";
            }
        }
    }
}