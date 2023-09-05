// Final Project Milestone 5
// Periodical Publication
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ji Ho Nam         Aug 2.2023
/////////////////////////////////////////////////////////////////
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include <iostream>
#include "Menu.h"
#include "Lib.h"
#include "Streamable.h"
#include "Publication.h"
#include "Book.h"

namespace sdds
{
    class LibApp
    {
    private:
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;

        char m_filename[SDDS_MAX_FILENAME + 1];
        Publication *m_PPA[SDDS_LIBRARY_CAPACITY]; // Publication pointers array
        int m_NOLP;                                // Number of loaded Publications
        int m_LLRN;                                // Last Library Reference Number

        Menu m_publicationType;

        // Instantiates a menu and initializes it with the message argument
        bool confirm(const char *message);

        // Simple private functions
        void load();
        void save();
        int search(int searchType);
        void returnPub();

        // Methods with confirmation
        void newPublication();
        void removePublication();
        void checkOutPub();

    public:
        LibApp(const char *fileName);
        ~LibApp();

        // Displays the main menu and based on the user's selection calls the corresponding private method and repeats the above until the user chooses to exit.
        void run();

        // Return the address of a Publication object in the PPA that has the library reference number matching the "libRef" argument.
        Publication *getPub(int libRef);
    };
}

#endif
