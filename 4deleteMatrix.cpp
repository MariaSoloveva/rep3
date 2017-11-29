#include <iostream>
#include <cstring>
#include "matrix.hpp"

void deleteMatrix(Matrix& m)
{
    float ** matrix = m.matrix;
    for (int i = 0; i < m.n; ++i)
        delete[] matrix[i];
    delete [] matrix;
    m.matrix = nullptr;
    m.n = 0;
    m.m = 0;
}
