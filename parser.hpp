#include <iostream>
#include <any>
#include <map>
#include <exception>
#include <sstream>
#include <fstream>
#include <vector>

class Json
{
    std::any _data;
public:
    Json(const std::map<std::string, std::any>& map)
    {
        _data = map;
    }
    Json(const std::vector<std::any>& vector)
    {
        _data = vector;
    }
    // Конструктор из строки, содержащей Json-данные.
    Json(const std::string& s)
    {
        for(size_t inner = 0; inner < s.size(); ++inner)
        {
            if (s[inner] == '{')
            {
                _data = parse_object(s, inner);
            }
            else if (s[inner] == '[')
            {
                _data = parse_array(s, inner);
            }
        }
    }
    // Метод возвращает true, если данный экземпляр содержит в себе JSON-массив. Иначе false.
    bool is_array() const
    {
        try {
            std::any_cast<std::vector<std::any>>(_data);
            return true;
        }
        catch(const std::bad_any_cast& e) {
            return false;
        }
    }

    // Метод возвращает true, если данный экземпляр содержит в себе JSON-объект. Иначе false.
    bool is_object() const
    {
        try {
            std::any_cast<std::map<std::string, std::any>>(_data);
            return true;
        }
        catch(const std::bad_any_cast& e) {
            return false;
        }
    }

    // Метод возвращает true, если данный экземпляр не содержит ничего, т.е. null. Иначе false.
    bool is_null() const
    {
        return _data.empty();
    }

    // Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
    // Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
    // Если экземпляр является JSON-массивом, генерируется исключение.
    std::any& operator[](const std::string& key)
    {
        if (is_object())
        {
            //std::map<std::string, boost::any> map;
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
    std::any& operator[](int index)
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
    const std::any& operator[](const std::string& key) const
    {
        if (is_object())
        {
            std::any copy = _data;
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
    const std::any& operator[](int index) const
    {
        if (is_array())
        {
            std::any copy = _data;
            auto& vector =  std::any_cast<std::vector<std::any>&>(copy);
            return vector[index];
        }
        else
        {
            throw std::logic_error("Error");
        }
    }
    std::map<std::string, std::any> parse_object(const std::string& s, size_t& position);
    std::vector<std::any> parse_array(const std::string& s, size_t& position);
    friend std::string parse_string(std::string& s, size_t& position);
    friend float parse_number(std::string& s, size_t& position);
    friend bool parse_bool(std::string& s, size_t& position);
    // Метод возвращает объект класса Json из строки, содержащей Json-данные.
    static Json parse(const std::string& s)
    {
        return Json(s);
    }

    // Метод возвращает объекта класса Json из файла, содержащего Json-данные в текстовом формате.
    static Json parseFile(const std::string& path_to_file)
    {
        std::ifstream file(path_to_file);
        std::string s = "";
        std::string line;
        while (std::getline(file, line))
            s += line;
        return Json(s);
    }
};
enum State
{
    find_key_or_end,
    find_colon,
    find_value,
    find_comma_or_end
};
std::string parse_string(const std::string& s, size_t& position)
{
    ++position;
    for (size_t inner = position; inner < s.size(); ++inner)
    {
        if (s[inner] == ':' || s[inner] == ',')
            throw std::logic_error("Something went wrong");
        else if (s[inner] == '"')
        {
            std::string str = s.substr(position, inner - position);
            position = inner;
            return str;
        }
    }
}
float parse_number(const std::string& s, size_t& position)
{
    for (size_t inner = position; inner < s.size(); ++inner)
    {
        if (s[inner] == ':')
            throw std::logic_error("Something went wrong");
        else if (s[inner] == ',' || s[inner] == ']' || s[inner] == '}')
        {
            std::string str = s.substr(position, inner - position);
            position = inner;
            return stof(str);
        }
    }
}
bool parse_bool(const std::string& s, size_t& position)
{

    if (s.find( "false") != std::string::npos)
    {
        return false;
    }
    else if (s.find( "true") != std::string::npos)
    {
        return true;
    }
    else {
        throw std::invalid_argument("Error");
    }
}
std::map<std::string, std::any> parse_object(const std::string& s, size_t& position);
std::vector<std::any> Json::parse_array(const std::string& s, size_t& position)
{
    std::vector<std::any> result;
    ++position;
    size_t commaPosition = position;
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
                result.emplace_back(parse_object(s, inner));
                state = find_comma_or_end;
            }
            else
                throw std::invalid_argument("Something went wrong");
        }
        else if (s[inner] == '[')
        {
            if (state == find_value)
            {
                result.emplace_back(parse_array(s, inner));
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
                ++commaPosition;
                std::string str = s.substr(commaPosition, inner - commaPosition);
                if (str.find("false") != std::string::npos || str.find("true") != std::string::npos)
                    result.emplace_back(parse_bool(s, commaPosition));
                else
                    result.emplace_back(parse_number(s, commaPosition));
                position = inner;
                return result;
            }
        }
        else if (s[inner] == ',')
        {
            if (state == find_value)
            {
                ++commaPosition;
                std::string str = s.substr(commaPosition, inner - commaPosition);
                if (str.find("false") != std::string::npos || str.find("true") != std::string::npos)
                    result.emplace_back(parse_bool(s, commaPosition));
                else
                    result.emplace_back(parse_number(s, commaPosition));
                commaPosition = inner;
            }
            else
                throw std::logic_error("Error");
        }
    }
}
std::map<std::string, std::any> Json::parse_object(const std::string& s, size_t& position)
{
    std::map<std::string, std::any> result;
    State state = find_key_or_end;
    std::string key;
    boost::any value;
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
                value = parse_string(s, inner);
                result[key] = value;
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
        else if (s[inner] != '\n' & s[inner] != '\t' & s[inner] != ' ')
        {
            if (state == find_value)
            {
                if (isdigit(s[inner]))
                {
                    result[key] = parse_number(s, inner);
                }
                else
                {
                    result[key] = parse_bool(s,inner);
                }
                state = find_key_or_end;
            }
        }

    }
}
