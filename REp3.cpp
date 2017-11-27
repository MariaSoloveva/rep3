#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
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
        fl << e.second.size() << std::endl;
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
    std::ifstream fl(filename);
    std::string strnumberOfGroups ;
    std::getline(fl, strnumberOfGroups);
    int numberOfGroups = atoi(strnumberOfGroups.c_str());
    std::string nameOfGroup;
    std::getline(fl, nameOfGroup);
    for (int i = 0; i < numberOfGroups; ++i)
    {
        std::vector<Student> vecStudent;
        std::string strnumberOfStudents ;
        std::getline(fl, strnumberOfStudents);
        int numberOfStudents = atoi(strnumberOfStudents.c_str());
        for (int j = 0; j < numberOfStudents; ++j)
        {
            Student student;
            std::getline(fl, student.Name);
            std::string strYear;
            std::getline(fl, strYear);
            student.Year = atoi(strYear.c_str());
            std::string strscores ;
            std::getline(fl, strscores);
            int scores = atoi(strscores.c_str());
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
