#include "lab08.hpp"

float findMaxOfScores(std::vector<float>& averageScores)
{
    float max = averageScores[0];
    for (float f : averageScores)
        if (max < f)
            max = f;
    return max;
}
