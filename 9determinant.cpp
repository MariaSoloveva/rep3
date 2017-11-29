#include <iostream>
#include <cstring>
#include "matrix.hpp"

float determinant(Matrix matrix)
{
    int l;
    float d;
    float sum11= 1;
    float sum12= 0;
    float sum21= 1;
    float sum22= 0;
    for (int i = 0; i < matrix.n; i++)
    {
        sum11 = 1; l = 2 *  - 1 - i; sum21 = 1;
        for (int j = 0; j < matrix.n; j++)
        {
            sum21 *= matrix.matrix[j][l % matrix.n];
            l--;
            sum11 *= matrix.matrix[j][(j+i) % (matrix.n)];
        }
        sum22 += sum21;
        sum12 += sum11;
    }
    d = sum12 - sum22;
    return d;
}
