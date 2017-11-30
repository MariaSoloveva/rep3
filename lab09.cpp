#include <iostream>
#include <cstring>
#include "iu_strings.hpp"
#include "matrix.hpp"


void getIn(Matrix& matrix1)
{
    for (int i = 0; i < matrix1.n; ++i)
    {
        for (int j = 0; j < matrix1.m; ++j)
        {
            matrix1.matrix[i][j] = 0;
        }
    }
}
void printMatrix(Matrix& matrix1)
{
    for (int i = 0; i < matrix1.n; ++i)
    {
        for (int j = 0; j < matrix1.m; ++j)
        {
            std::cout << matrix1.matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    // 1
    const char *p = "some string";
    char *newString = stringCopy(p);
    char *a = new char[strlen(p) + 1];
    a[strlen(p) + 1] = 0;
    strcpy(a, p);
    a[0] = 'S';
    std::cout << a << std::endl;
    std::cout << newString << std::endl;
    // 2
    const char *p0 = "Hello,";
    const char *p1 = " world!";
    char *newString1 = stringConcatinate(p0, p1);
    char *a0 = new char[strlen(p0) + 1];
    a0[strlen(p0) + 1] = 0;
    char *a1 = new char[strlen(p1) + 1];
    a1[strlen(p1) + 1] = 0;
    strcpy(a0, p0);
    strcpy(a1, p1);
    a0[0] = 'S';
    a1[0] = 'S';
    std::cout << newString1 << std::endl;
    // 3
    int n = 5;
    int m = 5;
    Matrix matrix = newMatrix(n, m);
    getIn(matrix);
    printMatrix(matrix);
    // 4
    n = 5;
    m = 4;
    Matrix matrix1 = newMatrix(n, m);
    getIn(matrix1);
    printMatrix(matrix1);
    deleteMatrix(matrix1);
    bool b = matrix1.matrix == nullptr;
    std::cout << b << std::endl;
    // 5
    n = 4;
    m = 4;
    matrix = newMatrix(n, m);
    snake(matrix);
    printMatrix(matrix);
    deleteMatrix(matrix);
    // 6
    n = 2;
    m = 2;
    Matrix matrixA = newMatrix(n, m);
    getIn(matrixA);
    std::cout << std::endl;
    printMatrix(matrixA);
    Matrix matrixB = copy(matrixA);
    std::cout << std::endl;
    printMatrix(matrixB);
    deleteMatrix(matrixA);
    deleteMatrix(matrixB);
    // 7
    n = 4;
    m = 3;
    Matrix matrix0 = newMatrix(n, m);
    getIn(matrix0);
    printMatrix(matrix0);
    std::cout << std::endl;
    Matrix matrixT = transpose(matrix0);
    printMatrix(matrixT);
    // 8
    n = 10;
    matrix = newMatrix(n, n);
    Matrix inv = inverse(matrix);
    deleteMatrix(matrix);
    // 9
    n = 10;
    m = 10;
    matrix = newMatrix(n, m);
    float d = determinant(matrix);
    deleteMatrix(matrix);
    // 10
    n = 10;
    m = 10;
    matrix = ones(n);
    printMatrix(matrix);
    float det = determinant(matrix);
    std::cout << det << std::endl;
    deleteMatrix(matrix);
    // 11
    n = 3;
    m = 4;
    int k = 4;
    Matrix matrixOne = newMatrix(n, m);
    getIn(matrixOne);
    printMatrix(matrixOne);
    std::cout << std :: endl;
    Matrix matrixTwo = newMatrix(m, k);
    getIn(matrixTwo);
    printMatrix(matrixTwo);
    Matrix matrixThree = mult(matrixOne, matrixTwo);
    printMatrix(matrixThree);
    deleteMatrix(matrixOne);
    deleteMatrix(matrixTwo);
    deleteMatrix(matrixThree);
    // 12
    n = 4;
    m = 4;
    matrixOne = newMatrix(n, m);
    getIn(matrixOne);
    matrixTwo = newMatrix(n, m);
    getIn(matrixTwo);
    bool db = (matrixOne == matrixTwo);
    deleteMatrix(matrixOne);
    deleteMatrix(matrixTwo);
    return 0;
}
