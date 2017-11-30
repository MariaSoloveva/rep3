#include <iostream>
#include <cstring>
#include "matrix.hpp"

bool operator==(const Matrix&, const Matrix&)
{
    int number = 0;
    int inner = 0;
    if ((aMatrix.n == bMatrix.n) && (aMatrix.m == bMatrix.m))
    {
        for (int i = 0; i < aMatrix.m; ++i)
        {
            for (int j = 0; j < aMatrix.n; ++j)
            {
                if (aMatrix.matrix[j][i] == bMatrix.matrix[j][i])
                    ++number;
                else
                {
                    ++inner;
                    break;
                }
            }
            if (inner == 1)
                break;
        }
        if (number == (aMatrix.n * aMatrix.m))
            return true;
        else
            return false;
    }
    else
        return false;
}
