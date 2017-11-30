#include <cmath>
#include <cstring>
#include <iostream>
#include "matrix.hpp"

void GetMatr(const Matrix matrix, Matrix tempMatr, int indRow, int indCol)
{
    int ki = 0;
    for (int i = 0; i < matrix.n; i++)
    {
        if(i != indRow)
        {
            for (int j = 0, kj = 0; j < matrix.n; j++)
            {
                if (j != indCol)
                {
                    tempMatr.matrix[ki][kj] = matrix.matrix[i][j];
                    kj++;
                }
            }
            ki++;
        }
    }
}
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
        std::cout << "the determinant is zero , matrix is singular" << std::endl;
        return matrix;
    }
}
