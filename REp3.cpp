#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Book
{
    std::string Author;
    std::string Title;
    int Year;
};
enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
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
    for (const auto& e : groups)
    {
        fl << e.first << std::endl;
        for (size_t i = 0; i < e.second.size(); ++i)
        {
            fl << e.second[i].Name << std::endl;
            fl << e.second[i].Year << std::endl;
            for (const auto& a : e.second[i].RecordBook)
            {
                fl << a.first << std::endl;
                fl << a.second << std::endl;
            }
        }
        std::cout << std::endl;
    }
}
