#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

void vectorToFile(const std::string& filename, std::vector<std::string>& data)
{
    std::ofstream fl(filename);
    for (int i = 0; i < data.size(); ++i)
    {
        fl << data[i];
        if (i < data.size() - 1)
            fl << std::endl;
    }
    fl.close();
}
void vectorFromFile(const std::string& filename, std::vector<std::string>& data)
{
    std::ifstream fl(filename);
    while (!fl.eof())
    {
        std::string str;
        fl >> str;
        data.push_back(str);
    }
}
void printVector(std::vector<std::string>& vec)
{
    for (auto v : vec)
        std::cout << v << " " ;
    std::cout << std::endl;
}
template<class K, class V>
void printMap(const std::map<K, V>& m)
{
    for (const auto& e : m)
        std::cout << e.first << ": " << e.second << std::endl;
}
struct Book
{
    std::string Author;
    std::string Title;
    int Year;
};
void saveToFileBook(const std::string& filename, const std::vector<Book>& data)
{
    std::fstream fl(filename, std::ios::out);
    for (size_t i = 0; i < data.size() ; ++i)
    {
        fl << data[i].Author << "-";
        fl << data[i].Title << "-";
        fl << data[i].Year << std::endl;
    }
}
std::string returnPart(std::string& str)
{
    char buf[str.length()];
    std::size_t length = str.copy(buf, str.find("-"), 0);
    str = str.substr(str.find("-") + 1);
    buf[length] = '\0';
    return buf;
}
int returnNumber(std::string& str)
{
    int number = 0;
    for (size_t j = 0; j < str.length(); ++j)
    {
        int digit1 = (int)str[j] - (int)'0';
        number = number * 10 + digit1;
    }
    return number;
}
void loadFromFile(const std::string& filename, std::vector<Book>& outData)
{
    std::ifstream fl(filename);
    std::string str;
    while (!fl.eof())
    {
        str.clear();
        std::getline(fl, str);
        Book Book1 =
        {
            returnPart(str),
            returnPart(str),
            returnNumber(str)
        };
        outData.push_back(Book1);
    }
}
enum Score
{
    Unsatisfactory = 2,
    Satisfactory,
    Good,
    Excellent
};
struct Student
{
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};
using Groups = std::map<std::string, std::vector<Student>>;
void saveToFileGroup(const std::string& filename, const Groups& groups)
{
    std::fstream fl(filename, std::ios::out);
    for (const auto& e : groups)
    {
        fl << e.first << "/";
        for (size_t i = 0; i < e.second.size(); ++i)
        {
            fl << e.second[i].Name << "/";
            fl << e.second[i].Year << "/";
            for (const auto& a : e.second[i].RecordBook)
            {
                fl << a.first << "/";
                fl << a.second << "/";
            }
        }
        std::cout << std::endl;
    }
}
std::string returnPartToStudent(std::string& str)
{
    char buf[str.length()];
    std::size_t length = str.copy(buf, str.find("/"), 0);
    str = str.substr(str.find("/") + 1);
    buf[length] = '\0';
    return buf;
}
int returnNumberForGroup(std::string& str)
{
    std::string strHelp = returnPartToStudent(str);
    return returnNumber(strHelp);
}
std::map<std::string, Score> returnRecordBook(std::string& str)
{
    std::map<std::string, Score> mp;
    while (str.size() > 0)
    {
        std::string strHelp = returnPartToStudent(str);
        mp.insert(std::pair<std::string, Score>(strHelp, Score(returnNumberForGroup(str))));
    }
    return mp;
};
void loadFromBook(const std::string& filename, Groups& groups)
{
    std::ifstream fl(filename);
    std::string str;
    while (!fl.eof())
    {
        str.clear();
        std::getline(fl, str);
        std::map<std::string, Score> RecordBook;
        std::string nameOfGroup = returnPartToStudent(str);
        std::vector<Student> vecOfStudents;
        {
            Student Student1 =
            {
                returnPartToStudent(str),
                returnNumberForGroup(str),
                returnRecordBook(str)
            };
            vecOfStudents.push_back(Student1);
        }
        groups.insert(std::pair<std::string, std::vector<Student>>(nameOfGroup, vecOfStudents));
    }
}
void printVector(const std::vector<Book> vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i].Author << std::endl;
        std::cout << vec[i].Title << std::endl;
        std::cout << vec[i].Year << std::endl;
    }
}
void printGroups(Groups& groups)
{
    for (const auto& e : groups)
    {
        std::cout << e.first << "/";
        for (size_t i = 0; i < e.second.size(); ++i)
        {
            std::cout << e.second[i].Name << "/";
            std::cout << e.second[i].Year << "/";
            for (const auto& a : e.second[i].RecordBook)
            {
                std::cout << a.first << "/";
                std::cout << a.second << "/";
            }
        }
        std::cout << std::endl;
    }
}
int main()
{
    std::vector<std::string> vec = {"ef", "kje", "fqeif", "u",
                                    "niwe", "fiuwenf", "ienf"};
    vectorToFile("vec.txt", vec);
    std::vector<std::string> out;
    vectorFromFile("vec.txt", out);
    printVector(out);
    std::vector<Book> vecOfBook = {{"Howard Phillips Lovecraft",
        "The Shadow Out of Time", 1934}, {"Edgar Allan Poe",
            "The Fall of the House of Usher", 1839}};
    saveToFileBook("structBook.txt", vecOfBook);
    std::vector<Book> vecOfBook1;
    saveToFileBook("structBook1.txt", vecOfBook);
    loadFromFile("structBook1.txt", vecOfBook1);
    printVector(vecOfBook1);
    Groups groups1;
    std::string nameOfGroup = "iu8-11";
    std::map<std::string, Score> RecordBook = {{"Math", Good}, {"English", Good}};
    std::vector<Student> student;
    {
        Student Student1 =
        {
            "Soloveva Maria",
            1999,
            RecordBook
        };
        student.push_back(Student1);
    }
    groups1.insert(std::pair<std::string, std::vector<Student>>(nameOfGroup, student));
    saveToFileGroup("Group.txt", groups1);
    Groups groups2;
    loadFromBook("Group.txt", groups2);
    saveToFileGroup("Group1.txt", groups2);
    printGroups(groups2);
    return 0;
}
