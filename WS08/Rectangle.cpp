#include <iostream>
#include <cstring>
#include "Rectangle.h"

namespace sdds
{
    Rectangle::Rectangle()
    {
        m_height = 0;
        m_width = 0;
    }

    Rectangle::Rectangle(const char *lbl, int width, int height) : LblShape(lbl)
    {
        int wid = strlen(label()) + 2;
        if (height < 3 || m_width < wid)
        {
            m_height = 0;
            m_width = 0;
        }
        else
        {
            m_height = height;
            m_width = width;
        }
    }

    void Rectangle::getSpecs(std::istream &is)
    {
        int width;
        int height;
        char temp;
        bool ret = false;

        do
        {
            LblShape::getSpecs(is);
            is >> width >> temp >> height;

            if (!is)
            {
                is.clear();
                is.ignore('\n');
            }
            else
            {
                is.ignore();
                m_height = height;
                m_width = width;
                ret = true;
            }
        } while (!ret);
    }

    void Rectangle::draw(std::ostream &os) const
    {
        if (m_width > 0 && m_height > 0)
        {
            os << '+';
            for (int i = 0; i < m_width - 2; ++i)
            {
                os << "-";
            }
            os << "+" << std::endl;

            os << '|';
            os.width(m_width - 2);
            os.fill(' ');
            os << std::left << label() << '|' << std::endl;

            for (int i = 0; i < (m_height - 3); i++)
            {
                os << '|';
                os.width(m_width - 2);
                os.fill(' ');
                os << ' ' << '|' << std::endl;
            }

            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+';
        }
    }
}