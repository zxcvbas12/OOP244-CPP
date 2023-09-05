/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Ji Ho Nam
Student ID#: 139817217
Email      : jhnam@myseneca.ca
Section    : OOP244NEE
Date       : Jul 09. 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "cstring.h"

using namespace std;

namespace sdds
{
    // Copies the srouce character string into the destination
    void strCpy(char *des, const char *src)
    {
        int i = 0;
        while (src[i] != '\0')
        {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
    }
    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char *des, const char *src, int len)
    {
        int i = 0;
        while (i < len && src[i] != '\0')
        {
            des[i] = src[i];
            i++;
        }
        while (i < len)
        {
            des[i] = '\0';
            i++;
        }
    }
    // Compares two C-strings
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strCmp(const char *s1, const char *s2)
    {
        int i = 0;
        while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        {
            i++;
        }
        return s1[i] - s2[i];
    }
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strnCmp(const char *s1, const char *s2, int len)
    {
        int i = 0;
        while (i < len && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        {
            i++;
        }
        return (i == len) ? 0 : (s1[i] - s2[i]);
    }
    // returns the lenght of the C-string in characters
    int strLen(const char *s)
    {
        int len = 0;
        while (s[len] != '\0')
        {
            len++;
        }
        return len;
    }
    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char *strStr(const char *str1, const char *str2)
    {
        int i, j;
        for (i = 0; str1[i] != '\0'; i++)
        {
            j = 0;
            while (str1[i + j] == str2[j] && str2[j] != '\0')
            {
                j++;
            }
            if (str2[j] == '\0')
                return &str1[i];
        }
        return nullptr;
    }
    // Concantinates "src" C-string to the end of "des"
    void strCat(char *des, const char *src)
    {
        int desLen = strLen(des);
        int i = 0;
        while (src[i] != '\0')
        {
            des[desLen + i] = src[i];
            i++;
        }
        des[desLen + i] = '\0';
    }
}