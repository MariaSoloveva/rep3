#include <cstring>
#include <iostream>
#include "matrix.hpp"

Matrix transpose(const Matrix& matrix1)
{
    Matrix matrix2 = newMatrix(matrix1.m, matrix1.n);
    for (int i = 0; i < matrix1.m; ++i)
        for (int j = 0; j < matrix1.n; ++j)
            matrix2.matrix[i][j] = matrix1.matrix[j][i];
    return matrix2;
}
