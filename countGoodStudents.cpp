#include "lab08.hpp"

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
