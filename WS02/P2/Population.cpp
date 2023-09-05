/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : May 27. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "Population.h"
#include "cstring.h"
#include "File.h"
using namespace std;
namespace sdds
{
    int temp;
    int codeOrder;
    Population *popNum;
    void sort()
    {
        int i, j;
        Population temp;
        for (i = codeOrder - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (popNum[j].people > popNum[j + 1].people)
                {
                    temp = popNum[j];
                    popNum[j] = popNum[j + 1];
                    popNum[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population &popNum)
    {
        bool ok = false;
        char name[128];

        if (read(name) && read(popNum.people))
        {
            popNum.code = new char[strLen(name) + 1];
            strCpy(popNum.code, name);
            ok = true;
        }
        return ok;
    }

    bool load(const char *filename)
    {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE))
        {
            codeOrder = noOfRecords();
            popNum = new Population[codeOrder];

            while (i < codeOrder)
            {
                if (load(popNum[i]))
                {
                    ok = true;
                    i++;
                }
                else
                {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                }
            }
        }
        else
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        closeFile();
        return ok;
    }

    void display(const Population &pop)
    {
        cout << pop.code << ":  " << pop.people << endl;
    }

    void display()
    {
        int i;
        cout << "Postal Code: population" << endl
             << "-------------------------" << endl;
        sort();

        for (i = 0; i < codeOrder; i++)
        {
            cout << i + 1 << "- ";
            display(popNum[i]);
            calculatePopulation(popNum[i]);
        }
        int total = calculatePopulation(*popNum);
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << total << endl;
    }

    int calculatePopulation(Population &pop)
    {
        temp += pop.people;

        return temp;
    }

    void deallocateMemory()
    {
        int i;
        for (i = 0; i < codeOrder; i++)
        {
            delete[] popNum[i].code;
        }
        delete[] popNum;
        popNum = nullptr;
    }

}