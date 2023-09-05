// Final Project Milestone 5
// Periodical Publication
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ji Ho Nam         Aug 1.2023
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
#include "Utils.h"
namespace sdds
{
    int getIntegerInput(int minRange, int maxRange, const char *message)
    {
        int input;
        bool validInt = false;
        while (validInt == false)
        {
            cin >> input;
            if (!cin || input < minRange || input > maxRange)
            {
                std::cout << message;
                cin.clear();
                cin.ignore(1000, '\n');
                validInt = false;
            }
            else
            {
                validInt = true;
            }
        }
        return input;
    }
}
