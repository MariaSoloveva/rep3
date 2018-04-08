#include <iostream>

class String
{
    char * Data;
 public:
    /// <summary> Деструктор </summary> 
    ~String();


    /// <summary> Конструктор по умолчанию </summary>  
    String();


    /// <summary> Конструктор копирования </summary>  
    /// <param name="rhs">Объект, который копируем </param>  
    String(const String& rhs);


    /// <summary> Пользовательский конструктор </summary>  
    /// <param name="data">Данные, которые требуется поместить в создаваемый объект </param>  
    String(const char * data);


    /// <summary> Оператор присваивания </summary>  
    /// <param name="data">Объект, который копируем </param>  
    /// <returns>Возвращаем ссылку на себя</returns>  
    String& operator=(const String& rhs);


    /// <summary> Оператор += </summary>  
    /// <param name="rhs">Объект, который стоит после знака '+=' </param>  
    /// <returns>Возвращаем ссылку на себя</returns>  
    String& operator+=(const String& rhs);


    /// <summary> Оператор == </summary>  
    /// <param name="rhs">Объект, который стоит после знака '==' </param>  
    /// <returns>Возвращаем значения равенства двух строк</returns>  
    bool operator==(const String& rhs) const;


    /// <summary> Оператор &lt; </summary>  
    /// <param name="rhs">Объект, который стоит после знака "&lt;" </param>  
    /// <returns>Возвращаем значения сравнения двух строк</returns>  
    bool operator<(const String& rhs) const;


    /// <summary> Функция поиска подстроки</summary>  
    /// <param name="substr">Подстрока, которую необходимо найти </param>  
    /// <returns>Возвращаем позицию substr. Если подстрока не найдена, то возвратить -1</returns> 
    size_t Find(const String& substr) const;


    /// <summary> Функция замены букв </summary>  
    /// <param name="oldSymbol">Символ, который требуется заменить </param>  
    /// <param name="newSymbol">Символ, на который требуется заменить </param>
    void Replace(char oldSymbol, char newSymbol);


    /// <summary> Функция возвращает длину строки </summary>  
    /// <returns>Возвращаем длину строки</returns> 
    size_t Size() const;


    /// <summary> Функция для определения пуста ли строка </summary>  
    bool Empty() const;


    /// <summary> Оператор [] </summary> 
    /// <example> 
    /// <code>
    /// String str = "some string";
    /// char symbol = str[2]; // symbol == 'm'
    /// </code>
    /// </example>
    /// <param name="index"> Индекс символа </param>  
    /// <returns> Значение символа в строке с индексом index</returns> 
    char operator[](size_t index) const;


    /// <summary> Оператор [] </summary> 
    /// <example> 
    /// <code>
    /// String str = "some string";
    /// str[0] = 'S'; // теперь переменная str равна "Some string"
    /// </code>
    /// </example>
    /// <param name="index"> Индекс символа </param>  
    /// <returns> Ссылка на символ в строке с индексом index</returns> 
    char& operator[](size_t index);


    /// <summary> Смотри пример </summary> 
    /// <example> 
    /// <code>
    /// String str = "___some string___";
    /// str.RTrim('_'); // теперь переменная str равна "___some string"
    /// </code>
    /// </example>
    /// <param name="symbol"> Значение символов, которе отрезаем </param> 
    void RTrim(char symbol);


    /// <summary> Смотри пример </summary> 
    /// <example> 
    /// <code>
    /// String str = "___some string___";
    /// str.LTrim('_'); // теперь переменная str равна "some string___"
    /// </code>
    /// </example>
    /// <param name="symbol"> Значение символов, которе отрезаем </param> 
    void LTrim(char symbol);

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
String operator+(const String& a, const String& b);


/// <summary> Оператор !=</summary>
bool operator!=(const String& a, const String& b);


/// <summary> Оператор &gt;</summary>
bool operator>(const String& a, const String& b);


/// <summary> Оператор вывода </summary>  
/// <param name="out">Поток куда выводим строку </param>  
/// <param name="str">Строка, которую выводим </param>
/// <returns>Возвращаем ссылку на поток</returns> 
std::ostream & operator<<(std::ostream& out, const String& str);
