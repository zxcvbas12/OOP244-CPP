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
using namespace std;

namespace sdds
{
    LabelMaker::LabelMaker(int noOfLabels) : m_labels(nullptr), m_noOfLabels(noOfLabels)
    {
        if (noOfLabels > 0)
            m_labels = new Label[noOfLabels];
    }

    void LabelMaker::readLabels()
    {
        cout << "Enter " << m_noOfLabels << " labels:" << endl;
        for (int i = 0; i < m_noOfLabels; i++)
        {
            cout << "Enter label number " << i + 1 << endl;
            cout << "> ";
            m_labels[i].readLabel();
        }
    }

    void LabelMaker::printLabels() const
    {
        for (int i = 0; i < m_noOfLabels; i++)
        {
            m_labels[i].printLabel() << endl;
        }
    }

    LabelMaker::~LabelMaker()
    {
        delete[] m_labels;
    }
}