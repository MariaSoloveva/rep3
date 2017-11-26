#include"lab08.hpp"

bool ratingUnsatisfactorily(Course& a)
{
    return a.Rating == Score::Unsatisfactorily;
}
int countNegligentStudents(std::vector<Student>& students)
{
    int numberOfBadStudents = 0;
    for (auto s : students)
    {
        bool cnt = std::count_if(s.RecordBook.begin(), s.RecordBook.end(), ratingUnsatisfactorily);
        if (cnt != 0)
        {
            ++numberOfBadStudents;
        }
    }
    return numberOfBadStudents;
}
