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
#include <iostream>
#include "Label.h"
#include "LabelMaker.h"
using namespace sdds;
using namespace std;
int main()
{
    int noOfLabels;
    // Create a lable for the program title:
    Label
        theProgram("/-\\|/-\\|", "The Label Maker Program"),
        EmptyOne1,
        EmptyOne2("ABCDEFGH");
    cout << "EmptyOne1" << endl;
    EmptyOne1.printLabel() << endl;
    cout << "EmptyOne2" << endl;
    EmptyOne2.printLabel() << endl;
    theProgram.printLabel() << endl
                            << endl;
    // ask for number of labels to get created
    cout << "Number of labels to create: ";
    cin >> noOfLabels;
    cin.ignore(10000, '\n');
    // Create a LabelMaker for the number of
    // the labels requested
    LabelMaker lblMkr(noOfLabels);
    // Ask for the label texts
    lblMkr.readLabels();
    // Print the labels
    lblMkr.printLabels();
    return 0;
}