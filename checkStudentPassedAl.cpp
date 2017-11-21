#include "lab08.hpp"

bool checkStudentPassedAl(std::vector<Student>& group)
{
    int numberOfGoodStudents = 0;
    for (size_t i = 0; i < group.size(); ++i)
    {
        for (size_t j = 0; j < group[i].RecordBook.size(); ++j)
        {
            if ((group[i].RecordBook[j].Title == "Al") &&
                (group[i].RecordBook[j].Rating == Excellent))
                ++numberOfGoodStudents;
        }
    }
    if (numberOfGoodStudents == group.size())
        return false;
    else
        return true;
}
