#include "lab08.hpp"

bool checkStudentFailedMl(std::vector<Student>& group)
{
    int numberOfBadStudents = 0;
    for (size_t i = 0; i < group.size(); ++i)
    {
        for (size_t j = 0; j < group[i].RecordBook.size(); ++j)
        {
            if ((group[i].RecordBook[j].Title == "Ml") &&
                (group[i].RecordBook[j].Rating == Unsatisfactorily))
                ++numberOfBadStudents;
        }
    }
    if (numberOfBadStudents == 0)
        return false;
    else
        return true;
}
