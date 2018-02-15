#include <algorithm>
#include <iostream>
#include "strings.hpp"


int StrLen(const char* strIn)
{
    int size = 0;
    for (; strIn[size] != 0; size++)
        continue;
    return size;
}
String::~String()
{
    delete[] Data;
}
String::String() : Data(nullptr) {}
String::String(const String& rhs)
{
    Data = new char[rhs.Size() + 1];
    memset(rhs.Date, Date, rhs.Size());
}
String::String(const char* data)
{
    Data = new char[StrLen(data)+1];
    memset(date, Date, StrLen(data));
}
String& String::operator=(const String& rhs)
{
    if (this != &rhs)
    {
        Data = nullptr;
        delete[] this->Data;
        Data = new char[rhs.Size()+1];
        memset(rhs.Data, Data, rhs.Size());
    }
    return *this;
}
String& String::operator+=(const String& rhs)
{
    int size = Size() + rhs.Size();
    char* newString = new char[size + 1];
    for (int i = 0; i < Size(); i++)
        newString[i] = Data[i];
    for (int k = Size(), j = 0; k <= size; k++, j++)
        newString[k] = rhs.Data[j];
    delete[] this->Data;
    Data = newString;
    return *this;
}
bool String::operator<(const String& rhs) const
{
    int i = 0;
    while (Data[i] == rhs.Data[i])
        ++i;
    return (Data[i] < rhs.Date[i]) ? true : false;
}
bool String::operator==(const String& rhs) const
{
    int i = 0;
    for (; (rhs.Data[i] == Data[i]) && (i < rhs.Size()); ++i)
        continue;
    return (i == rhs.Size()) ? true : false;
}
size_t String::Find(const String& substr) const
{
    size_t lenSub = substr.Size();
    if ((Size() - lenSub) > 0)
    {
        for (size_t i = 0; i < (Size() - lenSub); ++i)
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
    return Data[index];
}
char& String::operator[](size_t index)
{
    return Data[index];
}
void String::RTrim(char symbol)
{
    size_t sizeOfData = Size();
    for (; sizeOfData != -1; sizeOfData--)
        if (Data[sizeOfData - 1] != symbol)
            break;
    char* newData = new char[sizeOfData + 1];
    for (int i = 0; i < sizeOfData; ++i)
        newData[i] = Data[i];
    this->Data = nullptr;
    delete[] this->Data;
    Data = newData;
}
void String::LTrim(char symbol)
{
    size_t sizeOfData = 0;
    for (; Data[sizeOfData] != 0; ++sizeOfData)
        if (Data[sizeOfData] != symbol)
            break;
    char* newData = new char[Size() - sizeOfData + 1];
    for (int i = 0; Data[sizeOfData] != 0; ++sizeOfData, ++i)
        newData[i] = Data[sizeOfData];
    Data = nullptr;
    delete[] this->Data;
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
    return (!(b < a) && (a != b)) ? true : false;
}
std::ostream& operator<<(std::ostream& out, const String& str)
{
    return out << str.Data;
}

int main()
{
    const char* data = {"__some string__"};
    const char* data2 = {"Some String"};
    String stringFirst;
    String stringSecond(data);
    String stringCopy(stringSecond);
    String stringThird(data2);
    std::cout << stringFirst << std::endl;
    std::cout << "2   " << stringSecond << std::endl;
    std::cout << "3   " << stringThird << std::endl;
    std::cout << "Copy   " << stringCopy << std::endl;
    stringSecond = stringThird;
    std::cout << "2 after =   " << stringSecond << std::endl;
    stringSecond += stringCopy;
    std::cout << "2 after +=   " << stringSecond << std::endl;
    std::cout << "2 < 3 ? true : false   " << (stringSecond < stringThird)<< std::endl;
    std::cout << "2 > 3 ? true : false   " << (stringSecond > stringThird)<< std::endl;
    std::cout << "3   " << stringThird << std::endl;
    std::cout << "2 == 3  " << (stringThird == stringSecond) << std::endl;
    std::cout << "2 == 3  " << (stringSecond == stringSecond) << std::endl;
    std::cout << "2 != 3  " << (stringThird != stringSecond) << std::endl;
    stringSecond.Replace('s', 'S');
    std::cout << "2 replace 's' -> 'S' " << stringSecond << std::endl;
    std::cout << "find third string in second position"
        << stringSecond.Find(stringThird) << std::endl;
    stringSecond.Replace('S', 's');
    std::cout << "2 replace 'S' -> 's' " << stringSecond << std::endl;
    std::cout << "3   " << stringThird << std::endl;
    stringSecond.RTrim('_');
    stringSecond.LTrim('s');
    std::cout << "Delete '_' on left and right  " << stringSecond << std::endl;
    std::cout << "find third string in second " << stringSecond.Find(stringThird) << std::endl;
    std::cout << "2 size  " << stringSecond.Size() << std::endl;
    std::cout << "2 empty or not  " << stringSecond.Empty() << std::endl;
    return 0;
}
