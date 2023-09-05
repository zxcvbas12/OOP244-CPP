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
#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Food.h"
namespace sdds {
   class CalorieList {
      char m_title[37];
      Food* m_food;
      int m_noOfFood;
      int m_foodAdded;
      int totalTax()const;
      int totalCalories()const;
      void Title()const;
      void footer()const;
      void setEmpty();
      bool isValid()const;
   public:
      void init(int noOfItems);
      bool add(const char* item_name, int calories, int meal);
      void display()const;
      void deallocate();
   };
}
#endif // !SDDS_TRANSCRIPT_H
