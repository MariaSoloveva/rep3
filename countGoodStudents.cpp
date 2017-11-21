#include "lab08.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void loadFromFile(const std::string& filename, Groups& outGroups)
{
    std::string nameOfGroup;
    std::ifstream fl(filename);
    while (!fl.eof())
    {
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
