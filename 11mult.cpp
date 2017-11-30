#include <iostream>
#include <cstring>
#include "matrix.hpp"

Matrix operator*(const Matrix& aMatrix, const Matrix& bMatrix)
{
    Matrix product = newMatrix(aMatrix.n , bMatrix.m);
    for (int col = 0; col < bMatrix.m; col++)
    {
        for (int row = 0; row < aMatrix.n; row++)
        {
            for (int inner = 0; inner < bMatrix.n; inner++)
                product.matrix[row][col] += aMatrix.matrix[inner][col] * bMatrix.matrix[row][col];
        }
        std::cout << std::endl;
    }
    return product;
}
