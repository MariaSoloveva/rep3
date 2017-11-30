#include <iostream>
#include <cstring>
#include "matrix.hpp"

Matrix inverse(const Matrix& matrix)
{
    Matrix obrMatrix = newMatrix(matrix.n, matrix.n);
    float det = determinant(matrix);
    if (det)
    {
        for (int i = 0; i < matrix.n; i++)
        {
            for (int j = 0; j < matrix.n; j++)
            {
                int m = matrix.n - 1;
                Matrix tempMatr = newMatrix(m, m);
                GetMatr(matrix, tempMatr, i, j);
                obrMatrix.matrix[i][j] = pow(-1.0, i + j + 2) * determinant(tempMatr) / det;
                deleteMatrix(tempMatr);
            }
        }
        return obrMatrix;
    }
    else
    {
        std::cout << "Т.к. определитель матрицы = 0,\nто матрица вырожденная и обратной не имеет!!!" << std::endl;
        return matrix;
    }
}
