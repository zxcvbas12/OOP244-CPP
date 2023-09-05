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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "CalorieList.h"
using namespace sdds;
using namespace std;
const int c_breakfast = 1;
const int c_lunch = 2;
const int c_dinner = 3;
const int c_snack = 4;

void testDMA(CalorieList& CL);
int main() {
   CalorieList CL;
   CL.init(5);
   CL.add("Cheerios Cereal with 2% milk", 170, c_breakfast);
   CL.display();
   CL.add(nullptr, 100, c_breakfast);
   CL.add("Cheeseburger", 303, c_lunch);
   CL.add("Pepsi", 150, 0);
   CL.add("Apple", 52, c_snack);
   CL.display();
   CL.deallocate();
   CL.init(9);
   CL.add("Cheerios Cereal with 2% milk", 170, c_breakfast);
   CL.add("Tim Hortons Medium coffee double double", 230, c_breakfast);
   CL.add("Cheeseburger", 303, c_lunch);
   CL.add("French Fries", 312, c_lunch);
   CL.add("Pepsi", 150, c_lunch);
   CL.add("Apple", 52, c_snack);
   CL.add("Bread and Cheese", 195, c_dinner);
   CL.add("Garden Salad with Dressing", 220, c_dinner);
   if (!CL.add("Red Wine", 85, c_dinner)) {
      cout << "This should not be printed!" << endl;
   }
   
   if (CL.add("This should not be added", 100, c_dinner)) {
      cout << "This should not be printed!" << endl;
   }
   CL.display();
   CL.deallocate();
   //testDMA(CL); // uncommnet to test DMA
   return 0;
}

void testDMA(CalorieList& CL) {
   CL.init(1000);
   for (int i = 0; i < 1000; i++) {
      CL.add("Tim Hortons Medium coffee double double", 230, c_breakfast);
   }
   CL.display();
   CL.deallocate();
}