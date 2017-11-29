#include <iostream>
#include <cstring>
#include "matrix.hpp"

void snake(Matrix& matrix, int direction, int (*gen)(void))
{
    int i = 0;
    int j = 0;
    for (;;)
    {
        if (direction == 0)
        {
            while (j >= 0)
                matrix.matrix[i++][j--] = gen();
            j++;
            direction ^= 1;
            if (i == matrix.n)
                break;
        }
        else
        {
            while (i >= 0)
                matrix.matrix[i--][j++] = gen();
            while (i >= 0);
            i++;
            direction ^= 1;
            if (j == matrix.n)
                break;
        }
        if (direction == 0)
        {
            i = 1;
            j = matrix.n - 1;
        } else {
            i = matrix.n - 1;
            j = 1;
        }
        while (i != matrix.n && j != matrix.n)
        {
            if (direction == 0)
            {
                while (i < matrix.n)
                    matrix.matrix[i++][j--] = gen();
                i--;
                j += 2;
            }
            else
            {
                while (j < matrix.n)
                    matrix.matrix[i--][j++] = gen();
                j--;
                i += 2;
            }
            direction ^= 1;
        }
    }
}
int enterANumber()
{
    int n = 0;
    std::cin >> n;
    return n;
}
