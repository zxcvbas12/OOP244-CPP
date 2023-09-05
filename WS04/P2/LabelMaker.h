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
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
namespace sdds
{
    class LabelMaker
    {
        Label *m_labels;
        int m_noOfLabels;

    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels() const;
        ~LabelMaker();
    };
}
#endif
