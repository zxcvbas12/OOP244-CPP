/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #1 (P1)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : May 24. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "cstring.h" // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds
{

    int noOfEmployees;
    Employee *employees;

    void sort()
    {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (employees[j].m_empNo > employees[j + 1].m_empNo)
                {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee &emp)
    {
        bool ok = false;
        char name[128];

        if (read(emp.m_empNo) && read(emp.m_salary) && read(name))
        {
            emp.m_name = new char[strLen(name) + 1];
            strCpy(emp.m_name, name);
            ok = true;
        }
        return ok;
    }

    bool load()
    {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE))
        {
                           
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];

            while (i < noOfEmployees)
            {
                if (load(employees[i]))
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

    // TODO: Implementation for the display functions go here
    void display(const Employee &employees)
    {
        cout << employees.m_empNo << ": " << employees.m_name << ", " << employees.m_salary << endl;
    }

    void display()
    {
        int i;
        cout << "Employee Salary report, sorted by employee number" << endl
             << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        sort();

        for (i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }
    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory()
    {
        int i;
        for (i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].m_name;
        }
        delete[] employees;
        employees = nullptr;
    }
}