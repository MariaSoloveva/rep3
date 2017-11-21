#include<algorithm>
#include <iostream>
#include<string>

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
int countNegligentStudents(std::vector<Student>& group)
{
    int numberOfBadScores = 0;
    int numberOfBadStudents = 0;
    for (size_t i = 0; i < group.size(); ++i)
    {
        for (size_t j = 0; j < group[i].RecordBook.size(); ++j)
        {
            if (group[i].RecordBook[j].Rating == Unsatisfactorily)
                ++numberOfBadScores;
        }
        if (numberOfBadScores > 0)
            ++numberOfBadStudents;
        numberOfBadScores = 0;
    }
    return numberOfBadStudents;
}
int countGoodStudents(std::vector<Student>& group)
{
    int numberOfGoodScores = 0;
    int numberOfGoodStudents = 0;
    for (size_t i = 0; i < group.size(); ++i)
    {
        for (size_t j = 0; j < group[i].RecordBook.size(); ++j)
        {
            if (group[i].RecordBook[j].Rating == Excellent)
                ++numberOfGoodScores;
        }
        if (numberOfGoodScores == group[i].RecordBook.size())
            ++numberOfGoodStudents;
        numberOfGoodScores = 0;
    }
    return numberOfGoodStudents;
}
std::vector<float> findAverageScores (std::vector<Student>& group)
{
    std::vector<float> averageScore;
    int scores = 0;
    for (size_t i = 0; i < group.size(); ++i)
    {
        for (size_t j = 0; j < group[i].RecordBook.size(); ++j)
        {
            scores += group[i].RecordBook[j].Rating;
         }
        averageScore.push_back(scores / group[i].RecordBook.size());
        scores = 0;
    }
    return averageScore;
}
float findMaxOfScores(std::vector<float>& averageScores)
{
    float max = averageScores[0];
    for(float f : averageScores)
        if (max < f)
            max = f;
    return max;
}
void findStudentsgoodAtMath (std::vector<Student>& group)
{
    for (size_t i = 0; i < group.size(); ++i)
    {
        for (size_t j = 0; j < group[i].RecordBook.size(); ++j) {
            if ((group[i].RecordBook[j].Title == "Math") && (group[i].RecordBook[j].Rating == Excellent))
                std::cout << "Student number " << i + 1 << " is good at Math" << std::endl;
        }
    }
}
bool checkStudentFailedMl(std::vector<Student>& group)
{
    int numberOfBadStudents = 0;
    for (size_t i = 0; i < group.size(); ++i)
    {
        for (size_t j = 0; j < group[i].RecordBook.size(); ++j)
        {
            if ((group[i].RecordBook[j].Title == "Ml") && (group[i].RecordBook[j].Rating == Unsatisfactorily))
                ++numberOfBadStudents;
        }
    }
    if (numberOfBadStudents == 0)
        return false;
    else
        return true;
}
bool checkStudentPassedAl(std::vector<Student>& group)
{
    int numberOfGoodStudents = 0;
    for (size_t i = 0; i < group.size(); ++i)
    {
        for (size_t j = 0; j < group[i].RecordBook.size(); ++j)
        {
            if ((group[i].RecordBook[j].Title == "Al") && (group[i].RecordBook[j].Rating == Excellent))
                ++numberOfGoodStudents;
        }
    }
    if (numberOfGoodStudents == group.size())
        return false;
    else
        return true;
}
void printVector (std::vector<float>& vec)
{
    for (float f : vec)
        std::cout << f << ' ';
    std::cout << std::endl;
}
int main ()
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
    std::vector<Course> RecordBook1 = {{"Math", Unsatisfactorily}, {"Al", Unsatisfactorily}, {"Ml", Unsatisfactorily}};
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
