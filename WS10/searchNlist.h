/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "ReadWrite.h"
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"
using namespace std;
namespace sdds
{

  /*
  The listArrayElements template function accepts various types of arrays, titles, and their sizes, and outputs them to the console.
   It employs the <typename T> syntax to allow for different array types. During compilation, the function deduces the actual array type received.
   It starts by invoking the operator<< function of the abstract base class ReadWrite, as the Car, Employee, and Student classes inherit from it.
    Subsequently, it identifies the actual object type and calls the corresponding object's display() function
  */
  template <typename T>
  void listArrayElements(const char *_title, const T *_arr, int _num)
  {
    cout << _title << endl;

    for (int i = 0; i < _num; i++)
    {
      cout << (i + 1) << ": ";

      cout << _arr[i] << endl;
    }
  }

  /*
  The search template function works with the Collection template class, which can be specialized to hold objects of types like Car, Student, or Employee.
  The function receives a Collection object and an array of the same type. To handle different key types, it uses a separate type name.
  During compilation, the types are determined, and the function uses the == operator to compare the elements with the provided key.
  If a match is found, it utilizes the add template member function of the Collection class to add the data.
  */

  template <typename T1, typename T2>
  bool search(Collection<T1> &_obj, const T1 *_arr, int _num, T2 _key)
  {
    bool result = false;

    for (int i = 0; i < _num; i++)
    {
      if (_arr[i] == _key)
      {
        _obj.add(_arr[i]);
        result = true;
      }
    }
    return result;
  }
}
#endif // !SDDS_SEARCHNLIST_H_