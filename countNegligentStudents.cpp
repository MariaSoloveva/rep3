#include"lab08.hpp"

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
