#include "lab08.hpp"

int countGoodStudents(std::vector<Student>& students)
{
    int numberOfGoodStudents = 0;
    for (auto s : students)
    {
        bool cnt = std::all_of(s.RecordBook.begin(), s.RecordBook.end(), ratingExcellent);
        if (cnt != 0)
        {
            ++numberOfGoodStudents;
        }
    }
    return numberOfGoodStudents;
}
