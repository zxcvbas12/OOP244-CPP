/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : Jun 14. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
    void Account::setEmpty()
    {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account()
    {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance)
    {
        setEmpty();
        if (number >= 10000 && number <= 99999 && balance > 0)
        {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream &Account::display() const
    {
        if (*this)
        {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this)
        {
            cout << "  NEW  |         0.00 ";
        }
        else
        {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const
    {
        return (m_number != -1 && (m_number >= 10000 && m_number <= 99999) && m_balance >= 0.0);
    }

    Account::operator int() const
    {
        return m_number;
    }

    Account::operator double() const
    {
        return m_balance;
    }

    bool Account::operator~() const
    {
        return (m_number == 0);
    }

    Account &Account::operator=(int num)
    {
        if (~*this)
        {
            if (num < 10000 || num > 99999)
            {
                setEmpty();
            }
            else
            {
                m_number = num;
            }
        }
        return *this;
    }

    Account &Account::operator=(Account &src)
    {
        if (m_number != -1 && src)
        {
            m_number = src.m_number;
            m_balance = src.m_balance;

            src.m_balance = 0.0;
            src.m_number = 0;
        }

        return *this;
    }

    Account &Account::operator+=(double bal)
    {
        if (m_number != -1 && bal >= 0)
        {
            m_balance += bal;
        }
        return *this;
    }

    Account &Account::operator-=(double bal)
    {
        if (m_number != -1 && m_balance >= bal && bal >= 0)
        {
            m_balance -= bal;
        }
        return *this;
    }

    Account &Account::operator<<(Account &src)
    {
        if (m_number != -1 && src.m_number != -1 && this != &src)
        {
            m_balance += src.m_balance;
            src.m_balance = 0.0;
        }
        return *this;
    }

    Account &Account::operator>>(Account &src)
    {
        if (this != &src)
        {
            src.m_balance += m_balance;
            m_balance = 0.0;
        }
        return *this;
    }

    double operator+(const Account &src, const Account &src2)
    {
        double result = 0.0;
        if (src && src2)
        {
            result = src.operator double() + src2.operator double();
        }
        return result;
    }

    double operator+=(double &bal, const Account &src2)
    {
        if (src2)
        {
            bal += src2.operator double();
        }

        return bal;
    }
}
