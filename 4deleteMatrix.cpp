#include <iostream>
#include <cstring>
#include "matrix.hpp"

void deleteMatrix(Matrix& matrix1)
{
    for (int i = 0; i < matrix1.m; ++i)
        delete[]matrix1.matrix[i];
    //delete[]matrix1;
    //(matrix1.matrix) = nullptr;
}
