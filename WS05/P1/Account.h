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
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds
{
    class Account
    {
        int m_number;
        double m_balance;
        void setEmpty();

    public:
        Account();
        Account(int number, double balance);
        std::ostream &display() const;

        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator~() const;

        Account &operator=(int num);
        Account &operator=(Account &src);

        Account &operator+=(double bal);
        Account &operator-=(double bal);

        Account &operator<<(Account &src);
        Account &operator>>(Account &src);
    };

    double operator+(const Account &src, const Account &src2);
    double operator+=(double &bal, const Account &src2);
}
#endif // SDDS_ACCOUNT_H_
