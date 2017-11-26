#include "lab08.hpp"

bool ratingGoodAtAl(Course& a)
{
    return ((a.Rating != Score::Unsatisfactorily) && (a.Title == "Al"));
}
bool checkStudentPassedAl(std::vector<Student>& students)
{
    int numberOfBadStudents = 0;
    for (auto s : students)
    {
        int cnt = std::count_if(s.RecordBook.begin(), s.RecordBook.end(),
                                ratingGoodAtAl);
        if (cnt == 0)
            ++numberOfBadStudents;
    }
    if (numberOfBadStudents != 0)
        return false;
    else
        return true;
}
