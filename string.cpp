#include <cstring>
#include <iostream>
#include "string.hpp"

String::String()
    : Data(new char[1])
{
    Data[0] = '\0';
}
String::~String()
{
    delete[] Data;
}
String::String(const String& rhs)
    : Data(new char[rhs.Size() + 1])
{
    memcpy(Data, rhs.Data, rhs.Size() + 1);
}
String::String(const char* data)
{
    size_t size = 0;
    for (; data[size] != 0; size++)
        continue;
    Data = new char[size + 1];
    memcpy(Data, data, size + 1);
}
String& String::operator=(const String& rhs)
{
    if (this != &rhs)
    {
        delete[] Data;
        Data = new char[rhs.Size()+1];
        memcpy(Data, rhs.Data, rhs.Size() + 1);
    }
    return *this;
}

String& String::operator+=(const String& rhs)
{
    size_t size = Size() + rhs.Size();
    char* newString = new char[size + 1];
    //memcpy(newString, Data, rhs.Size());
    for (size_t k = Size() + 1, j = 0; k <= size; k++, j++)
        newString[k] = rhs.Data[j];
    delete[] Data;
    Data = newString;
    delete[] newString;
    return *this;
}
bool String::operator<(const String& rhs) const
{
    size_t i = 0;
    while ((Data[i] == rhs.Data[i]) && (i < Size()))
        ++i;
    return Data[i] < rhs.Data[i];
}
bool String::operator==(const String& rhs) const
{
    return Data == rhs.Data;
}
size_t String::Find(const String& substr) const
{
    for (size_t i = 0; i < Size() - substr.Size(); ++i)
    {
        for (size_t j = 0; j < substr.Size(); ++j)
        {
            if (substr.Data[j] != Data[i + j])
                return i;
        }
    }
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
    return Size() == 0;
}
char String::operator[](size_t index) const
{
    return Data[index];
}
char& String::operator[](size_t index)
{
    return Data[index];
}
void String::RTrim(char symbol)
{
    size_t sizeOfData = Size();
    while ((Data[sizeOfData - 1] == symbol) && (sizeOfData > 0))
            --sizeOfData;
    char* newData = new char[sizeOfData + 1];
    memcpy(newData, Data, sizeOfData);
    delete[] Data;
    newData[sizeOfData] = 0;
    Data = newData;
}
void String::LTrim(char symbol)
{
    size_t sizeOfData = 0;
    while (Data[sizeOfData] == symbol)
        ++sizeOfData;
    char* newData = new char[Size() - sizeOfData];
    int newSize = Size() - sizeOfData;
    for (int i = 0; Data[sizeOfData] != 0; ++sizeOfData, ++i)
        newData[i] = Data[sizeOfData];
    newData[newSize] = 0;
    delete[] Data;
    Data = newData;
}

String operator+(const String& a, const String& b)
{
    String c(a);
    return c += b;
}

bool operator!=(const String& a, const String& b)
{
    return !(a == b);
}

bool operator>(const String& a, const String& b)
{
    return ((b < a ) && (b != a));
}
std::ostream& operator<<(std::ostream& out, const String& str)
{
    return out << str.Data;
}
