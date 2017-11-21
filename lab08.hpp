#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

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

int countNegligentStudents(std::vector<Student>& group);
int countGoodStudents(std::vector<Student>& group);
std::vector<float> findAverageScores(std::vector<Student>& group);
float findMaxOfScores(std::vector<float>& averageScores);
void findStudentsgoodAtMath(std::vector<Student>& group);
bool checkStudentFailedMl(std::vector<Student>& group);
bool checkStudentPassedAl(std::vector<Student>& group);
