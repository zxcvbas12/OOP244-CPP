// Final Project Milestone 1
// Date Module
// File	Menu.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ji Ho Nam         Jul 08, 2023
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Menu.h"
#include "Utils.h"

namespace sdds
{
    MenuItem::MenuItem()
    {
        setEmpty();
    }

    MenuItem::MenuItem(const char *textContent)
    {
        if (textContent && textContent[0])
        {
            menuContent = new char[strLen(textContent) + 1];
            strCpy(menuContent, textContent);
        }
        else
        {
            setEmpty();
        }
    }

    MenuItem::~MenuItem()
    {
        delete[] menuContent;
    }

    void MenuItem::setEmpty()
    {
        menuContent = nullptr;
    }

    MenuItem::operator bool() const
    {
        return (menuContent && menuContent[0]);
    };

    MenuItem::operator const char *() const
    {
        return menuContent;
    }

    std::ostream &MenuItem::display(std::ostream &os)
    {
        if (*this)
        {
            os << menuContent;
        }

        return os;
    }

    Menu::Menu()
    {
        Count = 0;
    };

    Menu::Menu(const char *title) : menuTitle(title){};

    Menu::~Menu()
    {
        unsigned int i;
        for (i = 0; i < MAX_MENU_ITEMS; i++)
        {
            delete menuItems[i];
        }
    };

    std::ostream &Menu::displayMenuTitle(std::ostream &os)
    {
        if (menuTitle)
        {
            menuTitle.display();
        }

        return os;
    }

    std::ostream &Menu::displayMenu(std::ostream &os)
    {
        if (menuTitle)
        {
            menuTitle.display();
            os << ":" << std::endl;
        }

        unsigned int i;
        for (i = 0; i < Count; i++)
        {
            os.width(2);
            os.setf(std::ios::right);
            os.fill(' ');
            os << i + 1 << "- ";
            os.unsetf(std::ios::right);
            menuItems[i]->display(os);
            os << std::endl;
        }
        os << " 0- Exit" << std::endl;
        os << "> ";

        return os;
    }

    Menu::operator int()
    {
        return Count;
    }

    Menu::operator unsigned int()
    {
        return Count;
    }

    Menu::operator bool()
    {
        return (Count > 0);
    }

    std::ostream &operator<<(std::ostream &os, Menu &menu)
    {
        return (menu.displayMenuTitle(os));
    }

    int Menu::run()
    {
        unsigned int user_input;
        bool validInt = false;
        displayMenu();

        while (validInt == false)
        {
            std::cin >> user_input;

            if (!std::cin || user_input < 0 || user_input > Count)
            {
                std::cout << "Invalid Selection, try again: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                validInt = false;
            }
            else
            {
                validInt = true;
            }
        }

        return user_input;
    }

    int Menu::operator~()
    {
        return run();
    }

    Menu &Menu::operator<<(const char *content)
    {
        if (Count < MAX_MENU_ITEMS)
        {
            MenuItem *newMenuItem = new MenuItem(content);
            menuItems[Count] = newMenuItem;
            Count++;
        }

        return *this;
    }

    const char *Menu::operator[](unsigned int index) const
    {
        if (index > Count)
        {
            return menuItems[index %= Count]->menuContent;
        }
        else
        {
            return menuItems[index]->menuContent;
        }
    }
}