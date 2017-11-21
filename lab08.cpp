#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include"lab08.hpp"

enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Course
{
    std::string Title;
    Score Rating;
};

struct Student
{
    std::vector<Course> RecordBook;
};
void printVector(std::vector<float>& vec)
{
    for (float f : vec)
        std::cout << f << ' ';
    std::cout << std::endl;
}
int main()
{
    std::vector<Student> group;
    std::vector<Course> RecordBook = {{"Math", Excellent}, {"Al", Excellent}, {"Ml", Excellent}};
    {
        Student Student1 =
                {
                        RecordBook
                };
        group.push_back(Student1);
    }
    std::vector<Course> RecordBook1 = {{"Math", Unsatisfactorily},
                                       {"Al", Unsatisfactorily}, {"Ml", Unsatisfactorily}};
    {
        Student Student2 =
                {
                        RecordBook1
                };
        group.push_back(Student2);
    }
    for (size_t i = 0; i < group.size(); ++i)
    {
        for (size_t j = 0; j < group[i].RecordBook.size(); ++j)
        {
            std::cout << group[i].RecordBook[j].Title << std::endl;
            std::cout << group[i].RecordBook[j].Rating << std::endl;
        }
    }
    std::cout << "Number of negligent students " << countNegligentStudents(group) << std::endl;
    std::cout << "Number of good students " << countGoodStudents(group) << std::endl;
    findStudentsgoodAtMath(group);
    std::vector<float> averageScores = findAverageScores(group);
    printVector(averageScores);
    std::cout << "Max average score : " << findMaxOfScores(averageScores) << std::endl;
    if (checkStudentFailedMl(group) == false)
        std::cout << "Is there students that failed Ml? - No" << std::endl;
    else
        std::cout << "Is there students that failed Ml? - Yes" << std::endl;
    if (checkStudentPassedAl(group) == false)
        std::cout << "Is there students that failed Al? - No" << std::endl;
    else
        std::cout << "Is there students that failed Ml? - Yes" << std::endl;
}
