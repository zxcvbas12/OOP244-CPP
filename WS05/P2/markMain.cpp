/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : Jun 18. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "Mark.h"
using namespace std;
using namespace sdds;
int main()
{
    Mark m, n(25), k(200), p(-10);
    cout << "int ............" << endl;
    cout << int(m) << endl;
    cout << int(n) << endl;
    cout << int(k) << endl;
    cout << int(p) << endl;
    cout << "+= ............." << endl;
    cout << int(m += 20) << endl;
    cout << int(n += 20) << endl;
    cout << int(k += 20) << endl;
    cout << int(n += 60) << endl;
    cout << "= .............." << endl;
    cout << int(m = 80) << endl;
    cout << int(n = 120) << endl;
    cout << int(k = 70) << endl;
    cout << "double ........." << endl;
    m = 50;
    n = 80;
    k = 120;
    cout << double(m) << endl;
    cout << double(n) << endl;
    cout << double(k) << endl;
    cout << "char ..........." << endl;
    cout << char(m) << endl;
    cout << char(n) << endl;
    cout << char(k) << endl;
    cout << "int += Mark ..." << endl;
    int val = 60;
    cout << (val += n) << endl;
    cout << (val += k) << endl;
    return 0;
}