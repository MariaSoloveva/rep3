#include <cstring>
#include <iostream>
#include "matrix.hpp"

void snake(Matrix& matrix)
{
    int value = 0;
    int xy = 0;
    int yx = 0;
    for (int x = 0; x < matrix.n; x++)
        if (x % 2 == 0)
        {
            yx = 0;
            xy = x;
            while (xy >= 0)
            {
                matrix.matrix[xy][yx] = value;
                value++;
                xy--;
                yx++;
            }
        }
        else
        {
            yx = x;
            xy = 0;
            while (yx >= 0)
            {
                matrix.matrix[xy][yx] = value;
                value++;
                yx--;
                xy++;
            }
        }
    if (matrix.n % 2 == 1)
    {
        for (int y = 1; y < matrix.n; y++)
        {
            if (y % 2 == 1)
            {
                xy = y;
                yx = matrix.n - 1;
                while (yx >= y)
                {
                    matrix.matrix[xy][yx] = value;
                    value++;
                    xy++;
                    yx--;
                }
            }
            else
            {
                yx = y;
                xy = matrix.n - 1;
                while (xy >= y)
                {
                    matrix.matrix[xy][yx] = value;
                    value++;
                    xy--;
                    yx++;
                }
            }
        }
    }
    else
    {
        for (int x = 1; x < matrix.n; x++)
        {
            if (x % 2 == 1)
            {
                xy = matrix.n - 1;
                yx = x;
                while (xy >= x)
                {
                    matrix.matrix[xy][yx] = value;
                    value++;
                    xy--;
                    yx++;
                }
            }
            else
            {
                xy = x;
                yx = matrix.n - 1;
                while (yx >= x)
                {
                    matrix.matrix[xy][yx] = value;
                    value++;
                    xy++;
                    yx--;
                }
            }
        }
    }
}
