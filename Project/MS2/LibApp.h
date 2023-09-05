// Final Project Milestone 2
// Date Module
// File	Menu.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ji Ho Nam         Jul 14, 2023
/////////////////////////////////////////////////////////////////
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
namespace sdds
{
   class LibApp
   {
      bool m_changed;
      Menu m_mainMenu;
      Menu m_exitMenu;

      bool confirm(const char *message);
      void load();   // prints: "Loading Data"<NEWLINE>
      void save();   // prints: "Saving Data"<NEWLINE>
      void search(); // prints: "Searching for publication"<NEWLINE>

      void returnPub(); /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */

      void newPublication();
      void removePublication();
      void checkOutPub();

   public:
      LibApp();

      void run();
   };
}
#endif // !SDDS_LIBAPP_H
