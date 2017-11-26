#include "lab08.hpp"

bool ratingExcellent(Course& a)
{
    return a.Rating == Score::Excellent;
}
int countGoodStudents(std::vector<Student>& students)
{
    int numberOfGoodStudents = 0;
    for (auto s : students)
    {
        bool cnt = std::all_of(s.RecordBook.begin(), s.RecordBook.end(),
                               ratingExcellent);
        if (cnt != 0)
        {
            ++numberOfGoodStudents;
        }
    }
    return numberOfGoodStudents;
}
