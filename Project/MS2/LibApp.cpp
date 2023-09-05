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
#include "LibApp.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
#include "Menu.h"
namespace sdds
{
    bool LibApp::confirm(const char *message)
    {
        bool result = false;
        int canRun;
        Menu menu(message);
        menu << "Yes";

        canRun = menu.run();
        if (canRun)
        {
            result = true;
        }

        return result;
    }

    void LibApp::load()
    {
        std::cout << "Loading Data" << std::endl;
    }

    void LibApp::save()
    {
        std::cout << "Saving Data" << std::endl;
    }

    void LibApp::search()
    {
        std::cout << "Searching for publication" << std::endl;
    }

    void LibApp::returnPub()
    {
        search();
        std::cout << "Returning publication" << std::endl;
        std::cout << "Publication returned" << std::endl;
        m_changed = true;
    }

    void LibApp::newPublication()
    {
        std::cout << "Adding new publication to library" << std::endl;
        int result = confirm("Add this publication to library?");

        if (result)
        {
            m_changed = true;
            std::cout << "Publicaiton added" << std::endl;
        }
    }

    void LibApp::removePublication()
    {
        std::cout << "Removing publication from library" << std::endl;
        search();
        int result = confirm("Remove this publication from the library?");

        if (result)
        {
            m_changed = true;
            std::cout << "Publication removed" << std::endl;
        }
    }

    void LibApp::checkOutPub()
    {
        search();
        int result = confirm("Check out publication?");

        if (result)
        {
            m_changed = true;
            std::cout << "Publication checked out" << std::endl;
        }
    }

    LibApp::LibApp() : m_changed(false),
                       m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
        m_mainMenu << "Add New Publication";
        m_mainMenu << "Remove Publication";
        m_mainMenu << "Checkout publication from library";
        m_mainMenu << "Return publication to library";

        m_exitMenu << "Save changes and exit";
        m_exitMenu << "Cancel and go back to the main menu";
        load();
    }

    void LibApp::run()
    {
        int main_input;
        do
        {
            main_input = m_mainMenu.run();

            if (main_input == 1)
            {
                newPublication();
            }
            else if (main_input == 2)
            {
                removePublication();
            }
            else if (main_input == 3)
            {
                checkOutPub();
            }
            else if (main_input == 4)
            {
                returnPub();
            }
            else if (main_input == 0)
            {

                if (m_changed)
                {
                    int exit_input = m_exitMenu.run();
                    if (exit_input == 1)
                    {
                        save();
                    }
                    else if (exit_input == 2)
                    {
                        main_input = 1;
                    }
                    else if (exit_input == 0)
                    {
                        if (confirm("This will discard all the changes are you sure?"))
                        {
                            m_changed = true;
                        }
                    }
                }
            }
            std::cout << std::endl;
        } while (main_input != 0);

        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Thanks for using Seneca Library Application" << std::endl;
    }
}
