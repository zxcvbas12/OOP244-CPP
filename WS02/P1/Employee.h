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
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {
   struct Employee {
      char* m_name;
      int m_empNo;
      double m_salary;
   };
   //sorts the dynamic array of employees based on the GPA of the employees.
   void sort();
   // loads a employee structue with its values from the file
   bool load(Employee &emp);
   // allocates the dyanmic array of employees and loads all the file
   // recoreds into the array
   bool load();

   // TODO: Declare the prototype for the display function that
   // displays a employee record on the screen:
void display(const Employee &employees);
   // TODO: Declare the prototype for the display function that 
   // first sorts the employees then displays all the employees on the screen
   void display();
   // TODO: Declare the prototype for the deallocateMemory function that
   // first will deallocate all the names in the employee elements
   // then it will deallocate the employee array 
   void deallocateMemory();
}
#endif // SDDS_EMPLOYEE_H_