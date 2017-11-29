#include <iostream>
#include <cstring>
#include "matrix.hpp"

Matrix ones(int n)
{
    Matrix a = newMatrix(n, n);
    for (int i = 0; i < n ; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j || j == n - i - 1)
                a.matrix[i][j] = 1;
            else
                a.matrix[i][j] = 0;
        }
    }
    return a;
}
