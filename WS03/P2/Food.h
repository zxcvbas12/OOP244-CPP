/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : Jun 02. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#define rate 0.13
namespace sdds
{
   class Food
   {
      char foodName[30];
      int cal;
      int meal;
      void setName(const char *name);

   public:
      void setEmpty();
      void set(const char *name, int cal, int mealNum);
      void display() const;
      bool isValid() const;
      int calories() const;
      int mealtype() const;
   };
}
#endif