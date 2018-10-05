#include <iostream>
#include <any>
#include <map>
#include <vector>
#include <exception>
#include <sstream>
#include <fstream>

class Json
{
    std::any _data;
public:
    enum State
    {
        find_key_or_end,
        find_colon,
        find_value,
        find_comma_or_end
    };
    Json(const std::map<std::string, std::any>& map);
    Json(const std::vector<std::any>& vector);
    // Конструктор из строки, содержащей Json-данные.
    Json(const std::string& s);
    // Метод возвращает true, если данный экземпляр содержит в себе JSON-массив. Иначе false.
    bool is_array() const;

    // Метод возвращает true, если данный экземпляр содержит в себе JSON-объект. Иначе false.
    bool is_object() const;

    // Метод возвращает true, если данный экземпляр не содержит ничего, т.е. null. Иначе false.
    bool is_null() const;

    // Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
    // Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
    // Если экземпляр является JSON-массивом, генерируется исключение.
    std::any& operator[](const std::string& key);

    // Метод возвращает значение по индексу index, если экземпляр является JSON-массивом.
    // Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
    // Если экземпляр является JSON-объектом, генерируется исключение.
    std::any& operator[](int index);
    // Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
    // Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
    // Если экземпляр является JSON-массивом, генерируется исключение.
    const std::any& operator[](const std::string& key) const;

    // Метод возвращает значение по индексу index, если экземпляр является JSON-массивом.
    // Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
    // Если экземпляр является JSON-объектом, генерируется исключение.
    const std::any& operator[](int index) const;
    std::map<std::string, std::any> parse_object(const std::string& s, size_t& position);
    std::vector<std::any> parse_array(const std::string& s, size_t& position);
    friend std::string parse_string(std::string& s, size_t& position);
    friend float parse_number(std::string& s, size_t& position);
    friend bool parse_bool(std::string& s, size_t& position);
    friend void parse_null(std::string& s, size_t& position);
    // Метод возвращает объект класса Json из строки, содержащей Json-данные.
    static Json parse(const std::string& s);

    // Метод возвращает объекта класса Json из файла, содержащего Json-данные в текстовом формате.
    static Json parseFile(const std::string& path_to_file);
};
