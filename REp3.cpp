#include "string.h"
#include <iostream>

int StrLen(char* strIn)
{
    int size = 0;
    for (; strIn[size] != 0; size++)
        continue;
    return size;
}
void StrCopy(char* strOut, char* strIn)
{
    for (int i = 0; i < StrLen(strIn); i++)
        strOut[i] = strIn[i];
}
bool StrCmp(char* strFirst, char* strSecond)
{
    int i = 0;
    for (; (strFirst[i] == strSecond[i]) && (i < StrLen(strFirst)); ++i)
        continue;
    return (i == StrLen(strFirst)) ? true : false;
}

String::~String()
{
    delete[] Data;
}
String::String() : Data(nullptr) {}
String::String(const String& rhs)
{
    Data = new char[StrLen(rhs.Data)+1];
    StrCopy(Data, rhs.Data);
}
String::String(char* data)
{
    Data = new char[StrLen(data)+1];
    StrCopy(Data, data);
}
String& String::operator=(const String& rhs)
{
    if (this != &rhs)
    {
        delete[] this->Data;
        this->Data = new char[StrLen(rhs.Data)+1];
        StrCopy(this->Data, rhs.Data);
    }
    return *this;
}
String& String::operator+=(const String& rhs)
{
    int size = StrLen(this->Data) + StrLen(rhs.Data);
    char* newString = new char[size + 1];
    for (int i = 0; i < StrLen(this->Data); i++)
        newString[i] = this->Data[i];
    for (int k = StrLen(this->Data), j = 0; k <= size; k++, j++)
        newString[k] = rhs.Data[j];
    delete this->Data;
    this->Data = newString;
    return *this;
}
bool String::operator<(const String& rhs) const
{
    return (StrLen(Data) < StrLen(rhs.Data)) ? true : false;
}
bool String::operator==(const String& rhs) const
{
    return StrCmp(rhs.Data, Data);
}
size_t String::Find(const String& substr) const
{
    size_t lenSub = StrLen(substr.Data);
    if ((StrLen(Data) - lenSub) > 0)
    {
        for (size_t i = 0; i < (StrLen(Data) - lenSub); ++i)
        {
            int j = 0;
            bool flag = true;
            for (int k = i; k < lenSub; ++k)
            {
                if (Data[k] != substr.Data[j])
                    flag = false;
                ++j;
            }
            if (flag)
                return i;
        }
    }
    else
        return -1;
}
void String::Replace(char oldSymbol, char newSymbol)
{
    for (int i = 0; Data[i] != 0; ++i)
        if (Data[i] == oldSymbol)
            Data[i] = newSymbol;
}
size_t String::Size() const
{
    size_t sizeOfData = 0;
    for (; Data[sizeOfData] != 0; ++sizeOfData)
        continue;
    return sizeOfData;
}
bool String::Empty() const
{
    return (Data == nullptr) ? true : false;
}
char String::operator[](size_t index) const
{
    return (index >= 0 && index < StrLen(this->Data)) ? this->Data[index] : 0;
}
char& String::operator[](size_t index)
{
    static char emptyChar = 0;
    return (index >= 0 && index < StrLen(this->Data)) ? this->Data[index] : emptyChar;
}
void String::RTrim(char symbol)
{
    size_t sizeOfData = StrLen(Data);
    for (; sizeOfData != -1; sizeOfData--)
    {
        if (Data[sizeOfData - 1] != symbol)
            break;
    }
    std::cout << sizeOfData << std::endl;
    char* newData = new char[sizeOfData + 1];
    for (int i = 0; i < sizeOfData; ++i)
        newData[i] = Data[i];
    Data = newData;
}
void String::LTrim(char* Data, char symbol)
{
    size_t sizeOfData = 0;
    for (; Data[sizeOfData] != 0; ++sizeOfData)
    {
        if (Data[sizeOfData] != symbol)
            break;
    }
    char* newData = new char[StrLen(Data) - sizeOfData + 1];
    int i = 0;
    for (; Data[sizeOfData] != 0; ++sizeOfData)
    {
        newData[i] = Data[sizeOfData];
        ++i;
    }
    Data = newData;
}

String operator+(const String& a, const String& b)
{
    String c = a;
    return c += b;
}

bool operator!=(const String& a, const String& b)
{
    return !(a == b);
}

bool operator>(const String& a, const String& b)
{
    return (a < b) ? true : false;
}
std::ostream& operator<<(std::ostream& out, const String& str)
{
    return out << str.Data;
}
int main()
{
}
