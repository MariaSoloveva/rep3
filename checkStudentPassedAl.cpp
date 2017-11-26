#include "lab08.hpp"

bool checkStudentPassedAl(std::vector<Student>& students)
{
    int numberOfBadStudents = 0;
    for (auto s : students)
    {
        int cnt = std::count_if(s.RecordBook.begin(), s.RecordBook.end(), ratingGoodAtAl);
        if (cnt == 0)
            ++numberOfBadStudents;
    }
    if (numberOfBadStudents != 0)
        return false;
    else
        return true;
}
