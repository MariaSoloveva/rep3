#include <iostream>
#include <cstring>
#include "matrix.hpp"

Matrix newMatrix(int n, int m)
{
    float **ptr;
    ptr = new float*[n];
    for (int i = 0; i < m; i++)
        ptr[i] = new float[n];
    Matrix matrixStruct;
    matrixStruct.matrix = ptr;
    matrixStruct.n = n;
    matrixStruct.m = m;
    return matrixStruct;
}
