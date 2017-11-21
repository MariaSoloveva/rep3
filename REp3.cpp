#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void saveToFile(const std::string& filename, std::vector<std::string>& data)
{
    std::ofstream fl(filename);
    for (int i = 0; i < data.size(); ++i)
    {
        fl << data[i];
        if (i < data.size() - 1)
            fl << std::endl;
    }
}
void loadFromFile(const std::string& filename, std::vector<std::string>& data)
{
    std::ifstream fl(filename);
    std::string str;
    while (!fl.eof())
    {
        std::getline(fl, str);
        data.push_back(str);
    }
}
void printVector(std::vector<std::string>& vec)
{
    for (auto v : vec)
        std::cout << v << " ";
    std::cout << std::endl;
}
template<class K, class V>
void printMap(const std::map<K, V>& m);

template<class K, class V>
void printMap(const std::map<K, V> &m) {
    for (const auto& e : m)
        std::cout << e.first << ": " << e.second << std::endl;
}
struct Book
{
    std::string Author;
    std::string Title;
    int Year;
};
void saveToFile(const std::string& filename, const std::vector<Book>& data)
{
    std::fstream fl(filename, std::ios::out);
    for (size_t i = 0; i < data.size() ; ++i)
    {
        fl << data[i].Author << std::endl;
        fl << data[i].Title << std::endl;
        fl << data[i].Year << std::endl;
    }
}

void loadFromFile(const std::string& filename, std::vector<Book>& outData)
{

    Book book1;
    std::ifstream fl(filename);
    std::string str;
    while (!fl.eof())
    {
        str.clear();
        std::getline(fl, str);
        book1.Author = str;
        std::getline(fl, str);
        book1.Title = str;
        std::getline(fl, str);
        book1.Year = atoi(str.c_str());
        outData.push_back(book1);
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
void saveToFile(const std::string& filename, const Groups& groups)
{
    std::fstream fl(filename, std::ios::out);
    fl << groups.size() << std::endl;
    for (const auto& e : groups)
    {
        fl << e.first << std::endl;
        for (size_t i = 0; i < e.second.size(); ++i)
        {
            fl << e.second[i].Name << std::endl;
            fl << e.second[i].Year << std::endl;
            fl << e.second[i].RecordBook.size() << std::endl;
            for (const auto& a : e.second[i].RecordBook)
            {
                fl << a.first << std::endl;
                fl << a.second << std::endl;
            }
        }
        std::cout << std::endl;
    }
}
void loadFromFile(const std::string& filename, Groups& outGroups)
{
    std::string nameOfGroup;
    std::ifstream fl(filename);
    while (!fl.eof()) {
        int numberOfGroups = 0;
        fl >> numberOfGroups;
        for (int i = 0; i < numberOfGroups; ++i)
        {
            std::vector<Student> vecStudent;
            std::getline(fl, nameOfGroup);
            int numberOfStudents = 0;
            fl >> numberOfStudents;
            for (int j = 0; j < numberOfStudents; ++j)
            {
                Student student;
                std::getline(fl, student.Name);
                std::string strYear;
                std::getline(fl, strYear);
                student.Year = atoi(strYear.c_str());
                int scores = 0;
                fl >> scores;
                for (int k = 0; k < scores; ++k)
                {
                    std::string subjectName;
                    std::getline(fl, subjectName);
                    std::string grade;
                    std::getline(fl, grade);
                    student.RecordBook.insert(std::pair<std::string, Score>
                                                      (subjectName, Score(atoi(grade.c_str()))));
                }
                vecStudent.push_back(student);
            }
            outGroups.insert(std::pair<std::string, std::vector<Student>>(nameOfGroup, vecStudent));
        }
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
        std::cout << e.first << std::endl;
        for (size_t i = 0; i < e.second.size(); ++i)
        {
            std::cout << e.second[i].Name << std::endl;
            std::cout << e.second[i].Year << std::endl;
            for (const auto& a : e.second[i].RecordBook)
            {
                std::cout << a.first << std::endl;
                std::cout << a.second << std::endl;
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
    loadFromFile("vec.txt", out);
    printVector(out);
    std::vector<Book> vecOfBook = {{"Howard Phillips Lovecraft",
                                           "The Shadow Out of Time", 1934}, {"Edgar Allan Poe",
                                           "The Fall of the House of Usher", 1839}};
    saveToFile("structBook.txt", vecOfBook);
    std::vector<Book> vecOfBook1;
    saveToFile("structBook1.txt", vecOfBook);
    loadFromFile("structBook1.txt", vecOfBook1);
    printVector(vecOfBook1);*/
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
    saveToFile("Group.txt", groups1);
    Groups groups2;
    loadFromFile("Group.txt", groups2);
    saveToFile("Group1.txt", groups2);
    printGroups(groups2);
    return 0;
}
