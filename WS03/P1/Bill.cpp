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
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds
{

	void CalorieList::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool CalorieList::isValid() const
	{
		bool ok = false;

		if (m_title[0] != '\0' && m_items != nullptr)
		{
			for (int i = 0; i < m_noOfItems; i++)
			{
				ok = true;
				if (!m_items[i].isValid())
				{
					ok = false;
				}
			}
		}

		return ok;
	}

	double CalorieList::totalTax() const
	{
		double sum = 0.0;

		for (int i = 0; i < m_itemsAdded; i++)
		{
			sum += m_items[i].tax();
		}
		return sum;
	}

	double CalorieList::totalPrice() const
	{
		double sum = 0.0;

		for (int i = 0; i < m_itemsAdded; i++)
		{
			sum += m_items[i].price();
		}
		return sum;
	}

	void CalorieList::Title() const
	{
		cout << "+--------------------------------------+" << endl;

		if (isValid())
		{
			cout << "| " << m_title;
			for (int i = strLen(m_title); i < 36; i++)
			{
				cout << " ";
			}
			cout << " |" << endl;
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl
			 << "| Item Name            | Price   + Tax |" << endl
			 << "+----------------------+---------+-----+" << endl;
	}

	void CalorieList::footer() const
	{
		cout << "+----------------------+---------+-----+" << endl;

		if (isValid())
		{
			cout << "|                Total Tax: ";
			cout.precision(2);
			cout << setw(10);
			cout << totalTax() << " |" << endl;

			cout << "|              Total Price: ";
			cout.precision(2);
			cout << setw(10);
			cout << totalPrice() << " |" << endl;

			cout << "|          Total After Tax: ";
			cout.precision(2);
			cout << setw(10);
			cout << totalTax() + totalPrice() << " |" << endl;
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+--------------------------------------+" << endl;
	}

	void CalorieList::init(const char *title, int noOfItems)
	{
		if (title == nullptr || noOfItems <= 0)
		{
			setEmpty();
		}
		else
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];

			for (int i = 0; i < m_noOfItems; i++)
			{
				m_items[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char *item_name, double price, bool taxed)
	{
		bool ok = false;
		if (m_itemsAdded < m_noOfItems)
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			ok = true;
		}

		return ok;
	}

	void CalorieList::display() const
	{
		Title();

		for (int i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}

		footer();
	}

	void CalorieList::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}
}