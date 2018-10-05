#include "json.hpp"
#include <iostream>
#include <any>
#include <map>
#include <exception>
#include <sstream>
#include <fstream>

Json::Json(const std::map<std::string, std::any>& map)
{
    _data = map;
}
Json::Json(const std::vector<std::any>& vector)
{
    _data = vector;
}
// Конструктор из строки, содержащей Json-данные.
Json::Json(const std::string& s)
{
    for (size_t inner = 0; inner < s.size(); ++inner)
    {
        if (s[inner] == '{')
        {
            _data = parse_object(s, inner);
        }
        else if (s[inner] == '[')
        {
            _data = parse_array(s, inner);
        }
        else if (!isspace(s[inner]))
        {
            throw std::logic_error("Can't find a brace");
        }
    }
}
// Метод возвращает true, если данный экземпляр содержит в себе JSON-массив. Иначе false.
bool Json::is_array() const
{
    try
    {
        std::any_cast<std::vector<std::any>>(_data);
        return true;
    }
    catch(const boost::bad_any_cast& e)
    {
        return false;
    }
}

// Метод возвращает true, если данный экземпляр содержит в себе JSON-объект. Иначе false.
bool Json::is_object() const
{
    try
    {
        std::any_cast<std::map<std::string, std::any>>(_data);
        return true;
    }
    catch(const std::bad_any_cast& e)
    {
        return false;
    }
}

// Метод возвращает true, если данный экземпляр не содержит ничего, т.е. null. Иначе false.
bool Json::is_null() const
{
    return _data.empty();
}

// Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
// Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
// Если экземпляр является JSON-массивом, генерируется исключение.
std::any& Json::operator[](const std::string& key)
{
    if (is_object())
    {
        auto& map =  std::any_cast<std::map<std::string, std::any>&>(_data);
        return map[key];
    }
    else
    {
        throw std::logic_error("Error");
    }
}

// Метод возвращает значение по индексу index, если экземпляр является JSON-массивом.
// Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
// Если экземпляр является JSON-объектом, генерируется исключение.
std::any& Json::operator[](int index)
{
    if (is_array())
    {
        auto& vector =  std::any_cast<std::vector<std::any>&>(_data);
        return vector[index];
    }
    else
    {
        throw std::logic_error("Error");
    }
}

// Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
// Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
// Если экземпляр является JSON-массивом, генерируется исключение.
const std::any& Json::operator[](const std::string& key) const
{
    if (is_object())
    {
        auto copy = _data;
        auto& map =  std::any_cast<std::map<std::string, std::any>&>(copy);
        return map[key];
    }
    else
    {
        throw std::logic_error("Error");
    }
}

// Метод возвращает значение по индексу index, если экземпляр является JSON-массивом.
// Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
// Если экземпляр является JSON-объектом, генерируется исключение.
const std::any& Json::operator[](int index) const
{
    if (is_array())
    {
        auto copy = _data;
        auto& vector =  std::any_cast<std::vector<std::any>&>(copy);
        return vector[index];
    }
    else
    {
        throw std::logic_error("Error");
    }
}


Json Json::parse(const std::string& s)
{
    return Json(s);
}

// Метод возвращает объекта класса Json из файла, содержащего Json-данные в текстовом формате.
Json Json::parseFile(const std::string& path_to_file)
{
    std::ifstream file(path_to_file);
    std::string s;
    std::string line;
    while (std::getline(file, line))
        s += line;
    return Json(s);
}
std::string parse_string(const std::string& s, size_t& position)
{
    ++position;
    std::string str;
    for (size_t inner = position; inner < s.size(); ++inner)
    {
        if (s[inner] == ':' || s[inner] == ',')
            throw std::logic_error("Something went wrong");
        else if (s[inner] == '"')
        {
            str = s.substr(position, inner - position);
            position = inner;
            return str;
        }
    }
    return str;
}
float parse_number(const std::string& s, size_t& position)
{
    std::string str;
    for (size_t inner = position; inner < s.size(); ++inner)
    {
        if (isdigit(s[inner]) || s[inner] == '.')
            str += s[inner];
        else if (s[inner] == ',' || s[inner] == ']' || s[inner] == '}' || isspace(s[inner]))
        {
            position = --inner;
            return stof(str);
        }
        else
            throw std::invalid_argument("Something went wrong");
    }
    return stof(str);
}
bool parse_bool(const std::string& s, size_t& position)
{
    std::string str;
    for (size_t inner = position; inner < s.size(); ++inner)
    {
        if (isalpha(s[inner]))
            str += s[inner];
        else if (s[inner] == ',' || s[inner] == ']' || s[inner] == '}')
        {
            position = --inner;
            if (str == "false")
                return false;
            else if (str == "true")
                return true;
            else
                throw std::invalid_argument("Invalid argument");
        }
        else
            throw std::invalid_argument("Something went wrong");
    }
}

void parse_null(const std::string& s, size_t& position)
{
    while (isspace(s[position]))
    {
        ++position;
    }
}

std::vector<std::any> Json::parse_array(const std::string& s, size_t& position)
{
    std::vector<std::any> result;
    ++position;
    State state = find_value;
    for (size_t inner = position; inner < s.size(); ++inner)
    {
        if (s[inner] == '"')
        {
            if (state == find_value)
            {
                result.emplace_back(parse_string(s, inner));
                state = find_comma_or_end;
            }
            else
                throw std::invalid_argument("Something went wrong");
        }
        else if (s[inner] == '{')
        {
            if (state == find_value)
            {
                result.emplace_back(Json(parse_object(s, inner)));
                state = find_comma_or_end;
            }
            else
                throw std::invalid_argument("Something went wrong");
        }
        else if (s[inner] == '[')
        {
            if (state == find_value)
            {
                result.emplace_back(Json(parse_array(s, inner)));
                state = find_comma_or_end;
            }
            else
                throw std::invalid_argument("Something went wrong");
        }
        else if (s[inner] == ']')
        {
            if (state == find_comma_or_end)
            {
                position = inner;
                return result;
            }
            else if (state == find_value)
            {
                parse_null(s, inner);
                if (isdigit(s[inner]))
                {
                    result.emplace_back(parse_number(s, inner));
                }
                else if (isalpha(s[inner]))
                {
                    result.emplace_back(parse_bool(s, inner));
                }

                return result;
            }
        }
        else if (s[inner] == ',')
        {
            state = find_value;
        }
        else
        {
            if (state == find_value)
            {
                parse_null(s, inner);
                if (isdigit(s[inner]))
                {
                    result.emplace_back(parse_number(s, inner));
                }
                else if (isalpha(s[inner]))
                {
                    result.emplace_back(parse_bool(s, inner));
                }
                state = find_comma_or_end;
            }
            else if (!isspace(s[inner]))
                throw std::logic_error("Error");
        }
    }
}
std::map<std::string, std::any> Json::parse_object(const std::string& s, size_t& position)
{
    std::map<std::string, std::any> result;
    State state = find_key_or_end;
    std::string key;
    for (size_t inner = position; inner < s.size(); ++inner)
    {
        if (s[inner] == '"')
        {
            if (state == find_key_or_end)
            {
                key = parse_string(s, inner);
                state = find_colon;
            }
            else if (state == find_value)
            {
                result[key] = parse_string(s, inner);
                state = find_key_or_end;
            }
            else
            {
                throw std::logic_error("Something went wrong");
            }
        }
        else if (s[inner] == ':')
        {
            if (state == find_colon)
                state = find_value;
            else
                throw std::logic_error("Something went wrong");
        }
        else if (s[inner] == '{')
        {
            if (state == find_value)
            {
                result[key] = Json(parse_object(s, inner));
                state = find_key_or_end;
            }
        }
        else if (s[inner] == '}')
        {
            if (state == find_key_or_end || state == find_comma_or_end)
            {
                position = inner;
                return result;
            }
            else
                throw std::logic_error("Something went wrong");
        }

        else if (s[inner] == '[')
        {
            if (state == find_value)
            {
                result[key] = Json(parse_array(s, inner));
                state = find_key_or_end;
            }
        }
        else if (s[inner] == ']')
        {
            if (state == find_key_or_end || state == find_comma_or_end)
            {
                position = inner;
                return result;
            }
            else
                throw std::logic_error("Something went wrong");
        }
        else if (!isspace(s[inner]))
        {
            if (state == find_value)
            {
                if (isdigit(s[inner]))
                {
                    result[key] = parse_number(s, inner);
                }
                else
                {
                    result[key] = parse_bool(s, inner);
                }
                state = find_key_or_end;
            }
        }
    }
}


