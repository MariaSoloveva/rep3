#include <cstring>
#include <iostream>
#include "matrix.hpp"

Matrix copy(const Matrix& matrix1)
{
    Matrix matrix2 = newMatrix(matrix1.n, matrix1.m);
    for (int i = 0; i < matrix1.n; ++i)
    {
        for (int j = 0; j < matrix1.m; ++j)
        {
            matrix2.matrix[i][j] = matrix1.matrix[i][j];
        }
    }
    return matrix2;
}
