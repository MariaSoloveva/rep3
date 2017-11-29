#include <iostream>
#include <cstring>
#include "iu_strings.hpp"

char* stringCopy(const char* str)
{
    char * str2 = new char[strlen(str) + 1];
    str2[strlen(str) + 1] = 0;
    strcpy(str2, str);
    return str2;
}
