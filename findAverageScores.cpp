#include "lab08.hpp"

std::vector<float> findAverageScores(std::vector<Student>& group)
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
