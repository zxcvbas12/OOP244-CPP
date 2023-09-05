/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : Jul 09. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
using namespace sdds;
using namespace std;

void FirstTen(TextFile T);
void Copy(const string &dest, const string &source);
void Dump(const string &filename);
int main()
{
    TextFile Empty;
    TextFile BadFilename("badFilename");
    Copy("echoes.txt", "echoesOriginal.txt");
    Copy("seamus.txt", "seamusOriginal.txt");
    TextFile E;
    TextFile S("seamus.txt");
    cout << "Type echoes.txt and hit <ENTER>" << endl;
    cout << "Enter the text file name: ";
    cin >> E;
    cout << E << endl;
    cout << S << endl;
    FirstTen(E);
    FirstTen(S);
    E = S;
    cout << E << endl;
    cout << "============================================================" << endl;
    Dump("echoes.txt");
    Dump("seamus.txt");
    Dump("C_echoes.txt");
    Dump("C_seamus.txt");
    cout << "*" << Empty << BadFilename << "*" << endl;
    return 0;
}
void FirstTen(TextFile T)
{
    if (T)
    {
        cout << ">>> First ten lines of : " << T.name() << endl;
        for (unsigned i = 0; i < 10; i++)
        {
            cout << (i + 1) << ": " << T[i] << endl;
        }
    }
    else
    {
        cout << "Nothing to print!" << endl;
    }
    cout << endl
         << "-------------------------------------------------------------" << endl;
}
void Dump(const string &filename)
{
    cout << "DUMP---------------------------------------------------------" << endl;
    cout << ">>>" << filename << "<<<" << endl;
    ifstream fin(filename.c_str());
    char ch;
    while (fin.get(ch))
        cout << ch;
    cout << endl
         << "-------------------------------------------------------------" << endl;
}
void Copy(const string &dest, const string &source)
{
    ifstream fin(source.c_str());
    ofstream fout(dest.c_str());
    char ch;
    while (fin.get(ch))
        fout << ch;
}