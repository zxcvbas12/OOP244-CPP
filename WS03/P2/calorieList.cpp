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
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "calorieList.h"
using namespace std;
namespace sdds
{

	void CalorieList::setEmpty()
	{
		m_title[0] = '\0';
		m_food = nullptr;
	}

	bool CalorieList::isValid() const
	{
		bool ok = false;

		if (m_title[0] != '\0' && m_food != nullptr)
		{
			for (int i = 0; i < m_noOfFood; i++)
			{
				ok = true;
				if (!m_food[i].isValid())
				{
					ok = false;
				}
			}
		}

		return ok;
	}

	int CalorieList::totalTax() const
	{
		int sum = 0;

		for (int i = 0; i < m_foodAdded; i++)
		{
			sum += m_food[i].calories();
		}
		return sum;
	}

	int CalorieList::totalCalories() const
	{
		double sum = 0;

		for (int i = 0; i < m_foodAdded; i++)
		{
			sum += m_food[i].mealtype();
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
			cout << totalCalories() << " |" << endl;

			cout << "|          Total After Tax: ";
			cout.precision(2);
			cout << setw(10);
			cout << totalTax() + totalCalories() << " |" << endl;
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+--------------------------------------+" << endl;
	}

	void CalorieList::init(int noOfItems)
	{
		if (noOfItems <= 0)
		{
			setEmpty();
		}
		else
		{
			m_noOfFood = noOfItems;
			m_foodAdded = 0;
			m_food = new Food[m_noOfFood];

			for (int i = 0; i < m_noOfFood; i++)
			{
				m_food[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char *item_name, int calories, int meal)
	{
		bool ok = false;
		if (m_foodAdded < m_noOfFood)
		{
			m_food[m_foodAdded].set(item_name, calories, meal);
			m_foodAdded++;
			ok = true;
		}

		return ok;
	}

	void CalorieList::display() const
	{
		Title();

		for (int i = 0; i < m_noOfFood; i++)
		{
			m_food[i].display();
		}

		footer();
	}

	void CalorieList::deallocate()
	{
		delete[] m_food;
		m_food = nullptr;
	}
}