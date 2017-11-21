#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "lab08.hpp"

void printVector(std::vector<std::string>& vec)
{
    for (auto v : vec)
        std::cout << v << " ";
    std::cout << std::endl;
}

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
    saveToFile("Group.txt", groups1);
    Groups groups2;
    loadFromFile("Group.txt", groups2);
    saveToFile("Group1.txt", groups2);
    printGroups(groups2);
    return 0;
}
