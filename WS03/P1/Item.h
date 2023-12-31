/*/////////////////////////////////////////////////////////////////////////
                    Workshop - #3 (P1)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : May 31. 2023

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
   class Item
   {
      char foodName[21];
      double m_price;
      bool m_taxed;
      void setName(const char *name);

   public:
      void setEmpty();
      void set(const char *name, double price, bool taxed);
      void display() const;
      bool isValid() const;
      double price() const;
      double tax() const;
   };
}

#endif // !SDDS_SUBJECT_H
