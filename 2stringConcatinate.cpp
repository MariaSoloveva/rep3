#include <cstring>
#include <iostream>
#include "iu_strings.hpp"

char* stringConcatinate(const char* str0, const char* str1)
{
    char * str2 = new char[strlen(str0) + strlen(str0) + 1];
    str2[strlen(str0) + strlen(str0) + 1] = 0;
    strcpy(str2, str0);
    strcat(str2, str1);
    return str2;
}
