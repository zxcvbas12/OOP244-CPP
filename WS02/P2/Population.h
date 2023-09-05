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
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#define DATAFILE "PCpopulations.csv"
namespace sdds
{
    struct Population
    {
        char *code;
        int people;
    };

    void sort();
    bool load(Population &popNum);
    bool load(const char *filename);
    void display();
    void display();
    int calculatePopulation(Population &pop);
    void deallocateMemory();

}
#endif // SDDS_POPULATION_H_