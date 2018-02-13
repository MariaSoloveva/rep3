#include <iostream>

int StrLen(char* strIn);
void StrCopy(char* strOut, char* strIn);
bool StrCmp(char* strFirst, char* strSecond);

class String
{
    char * Data;

    public:
    /// <summary> Деструктор </summary>
    ~String()
    {
        delete[] Data;
    }
    /// <summary> Конструктор по умолчанию </summary>
    String();
    /// <summary> Конструктор копирования </summary>
    /// <param name="rhs">Объект, который копируем </param>
    String(const String& rhs)
    {
        Data = new char[StrLen(rhs.Data)+1];
        StrCopy(Data, rhs.Data);
    }
    /// <summary> Пользовательский конструктор </summary>
    /// <param name="data">Данные, которые требуется поместить в создаваемый объект </param>
    String(char* data)
    {
        Data = new char[StrLen(data)+1];
        StrCopy(Data, data);
    }
    /// <summary> Оператор присваивания </summary>
    /// <param name="data">Объект, который копируем </param>
    /// <returns>Возвращаем ссылку на себя</returns>
    String& operator=(const String& rhs)
    {
        if (this != &rhs)
        {
            delete[] this->Data;
            this->Data = new char[StrLen(rhs.Data)+1];
            StrCopy(this->Data, rhs.Data);
        }
        return *this;
    }
    /// <summary> Оператор += </summary>
    /// <param name="rhs">Объект, который стоит после знака '+=' </param>
    /// <returns>Возвращаем ссылку на себя</returns>
    String& operator+=(const String& rhs)
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
    /// <summary> Оператор == </summary>
    /// <param name="rhs">Объект, который стоит после знака '==' </param>
    /// <returns>Возвращаем значения равенства двух строк</returns>
    bool operator==(const String& rhs) const
    {
        return StrCmp(rhs.Data, Data);
    }

    /// <summary> Оператор &lt; </summary>
    /// <param name="rhs">Объект, который стоит после знака "&lt;" </param>
    /// <returns>Возвращаем значения сравнения двух строк</returns>
    bool operator<(const String& rhs) const
    {
        return (StrLen(Data) < StrLen(rhs.Data)) ? true : false;
    }
    /// <summary> Функция поиска подстроки</summary>
    /// <param name="substr">Подстрока, которую необходимо найти </param>
    /// <returns>Возвращаем позицию substr. Если подстрока не найдена, то возвратить -1</returns>
    size_t Find(const String& substr) const
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

    /// <summary> Функция замены букв </summary>
    /// <param name="oldSymbol">Символ, который требуется заменить </param>
    /// <param name="newSymbol">Символ, на который требуется заменить </param>
    void Replace(char oldSymbol, char newSymbol)
    {
        for (int i = 0; Data[i] != 0; ++i)
            if (Data[i] == oldSymbol)
                Data[i] = newSymbol;
    }

    /// <summary> Функция возвращает длину строки </summary>
    /// <returns>Возвращаем длину строки</returns>
    size_t Size() const
    {
        size_t sizeOfData = 0;
        for (; Data[sizeOfData] != 0; ++sizeOfData);
        return sizeOfData;
    }

    /// <summary> Функция для определения пуста ли строка </summary>
    bool Empty() const
    {
        return (Data == nullptr) ? true : false;
    }

    /// <summary> Оператор [] </summary>
    /// <example>
    /// <code>
    /// String str = "some string";
    /// char symbol = str[2]; // symbol == 'm'
    /// </code>
    /// </example>
    /// <param name="index"> Индекс символа </param>
    /// <returns> Значение символа в строке с индексом index</returns>
    char operator[](size_t index) const
    {
    //std::cerr << "Index out of range. \n";
        return (index >= 0 && index < StrLen(this->Data)) ? this->Data[index] : 0;
    }
    /// <summary> Оператор [] </summary>
    /// <example>
    /// <code>
    /// String str = "some string";
    /// str[0] = 'S'; // теперь переменная str равна "Some string"
    /// </code>
    /// </example>
    /// <param name="index"> Индекс символа </param>
    /// <returns> Ссылка на символ в строке с индексом index</returns>
    char& operator[](size_t index)
    {
        static char emptyChar = '';
        //std::cerr << "Index out of range. \n";
        return (index >= 0 && index < StrLen(this->Data)) ? this->Data[index] : emptyChar;
    }

    /// <summary> Смотри пример </summary>
    /// <example>
    /// <code>
    /// String str = "___some string___";
    /// str.RTrim('_'); // теперь переменная str равна "___some string"
    /// </code>
    /// </example>
    /// <param name="symbol"> Значение символов, которе отрезаем </param>
    void RTrim(char symbol)
    {

    }

    /// <summary> Смотри пример </summary>
    /// <example>
    /// <code>
    /// String str = "___some string___";
    /// str.LTrim('_'); // теперь переменная str равна "some string___"
    /// </code>
    /// </example>
    /// <param name="symbol"> Значение символов, которе отрезаем </param>
    void LTrim(char symbol)
    {

    }

    friend std::ostream& operator<<(std::ostream&, const String&);
};

/// <summary> Оператор +</summary>
/// <example>
/// <code>
/// String a = "Hello";
/// String b = "World";
/// String c = a + b; // c равна "HelloWorld"
/// </code>
/// </example>
/// <returns>Возвращаем строку равную a + b</returns>
String operator+(const String& a, const String& b)
{
    String c = a;
    return c += b;
}

/// <summary> Оператор !=</summary>
bool operator!=(const String& a, const String& b)
{
    return !(StrCmp(a.Data, b.Data));
}

/// <summary> Оператор &gt;</summary>
bool operator>(const String& a, const String& b)
{
    return (StrLen(a.Data) > StrLen(b.Data)) ? true : false;
}

/// <summary> Оператор вывода </summary>
/// <param name="out">Поток куда выводим строку </param>
/// <param name="str">Строка, которую выводим </param>
/// <returns>Возвращаем ссылку на поток</returns>
std::ostream& operator<<(std::ostream& out, const String& str)
{
    return out << str.Data;
}

int StrLen(char* strIn)
{
    int size = 0;
    for (; strIn[size] != 0; size++);
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
    for (; (strFirst[i] == strSecond[i]) && (i < StrLen(strFirst)); ++i);
    return (i == StrLen(strFirst)) ? true : false;
}
int main()
{

}
