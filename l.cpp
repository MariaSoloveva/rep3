#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include"lab08.hpp"

bool ratingUnsatisfactorily(Course& a)
{
    return a.Rating == Score::Unsatisfactorily;
}
bool ratingExcellent(Course& a)
{
    return a.Rating == Score::Excellent;
}
bool ratingExcellentAtMath(Course& a)
{
    return ((a.Rating == Score::Unsatisfactorily) && (a.Title == "Math"));
}
void printVector(std::vector<float>& vec)
{
    for (float f : vec)
        std::cout << f << ' ';
    std::cout << std::endl;
}
bool ratingGoodAtAl(Course& a)
{
    return ((a.Rating != Score::Unsatisfactorily) && (a.Title == "Al"));
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
    std::vector<Course> RecordBook1 = {{"Math", Unsatisfactorily}, {"Al", Unsatisfactorily},
                                       {"Ml", Unsatisfactorily}};
    {
        Student Student2 =
                {
                        RecordBook1
                };
        group.push_back(Student2);
    }
    std::cout << "Number of negligent students " << countNegligentStudents(group) << std::endl;
    std::cout << "Number of good students " << countGoodStudents(group) << std::endl;
    findStudentsgoodAtMath(group);
    std::vector<float> averageScores = findAverageScores(group);
    printVector(averageScores);
    std::cout << "Max average score : " << findMaxOfScores(averageScores) << std::endl;
    if (checkStudentFailedMl(group) == false)
        std::cout << "Is there any students that failed Ml? - No" << std::endl;
    else
        std::cout << "Is there any students that failed Ml? - Yes" << std::endl;
    if (checkStudentPassedAl(group) == true)
        std::cout << "All students passed Al? - Yes" << std::endl;
    else
        std::cout << "All students passed Al? - No" << std::endl;
    return 0;
}
