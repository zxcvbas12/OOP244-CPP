#include <iostream>
#include <cstring>
#include "LblShape.h"

namespace sdds
{
    LblShape::LblShape()
    {
        m_label = nullptr;
    }

    LblShape::LblShape(const char *label)
    {
        if (label)
        {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
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
        // Read label from istream up to ',' character
        delete[] m_label; // Release any existing memory
        m_label = nullptr;

        char comma;
        is >> std::ws; // Skip whitespace
        if (is.peek() != ',')
        {
            char buffer[1000]; // Adjust buffer size as needed
            is.get(buffer, sizeof(buffer), ',');
            is >> comma;
            m_label = new char[strlen(buffer) + 1];
            strcpy(m_label, buffer);
        }
        else
        {
            is >> comma; // Consume the comma if there's no label
        }
    }

    const char *LblShape::label() const
    {
        return m_label;
    }

}