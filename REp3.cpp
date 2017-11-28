#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
// 1
char* stringCopy(const char* str)
{
    char * str2 = new char[strlen(str) + 1];
    str2[strlen(str) + 1] = 0;
    strcpy(str2, str);
    return str2;
}
// 2
char* stringConcatinate(const char* str0, const char* str1)
{
    char * str2 = new char[strlen(str0) + strlen(str0) + 1];
    str2[strlen(str0) + strlen(str0) + 1] = 0;
    strcpy(str2, str0);
    strcat(str2, str1);
    return str2;
}
// 3
struct Matrix
{
    float ** matrix;
    int n;
    int m;
};
Matrix newMatrix(int n, int m)
{
    float **ptr;
    ptr = new float*[n];
    for(int i = 0; i < m; i++)
        ptr[i] = new float[n];
    Matrix matrixStruct;
    matrixStruct.matrix = ptr;
    matrixStruct.n = n;
    matrixStruct.m = m;
    return matrixStruct;
}
void getIn (Matrix& matrix1)
{
    for(int i = 0; i < matrix1.n; ++i)
    {
        for (int j = 0; j < matrix1.m; ++j)
        {
            matrix1.matrix[i][j] = 0;
        }
    }
}
void printMatrix (Matrix& matrix1)
{
    for(int i = 0; i < matrix1.n; ++i)
    {
        for (int j = 0; j < matrix1.m; ++j)
        {
            std::cout << matrix1.matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// 4
void deleteMatrix (Matrix& matrix1)
{
    for (int i = 0; i < matrix1.m; ++i)
        delete[]matrix1.matrix[i];
    delete[]matrix1;
    (matrix1.matrix) = nullptr;
}
// 5
void snake (Matrix& matrix, int direction, int (*gen)(void)) {
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
        } else
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
            } else
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
int enterANumber ()
{
    int n = 0;
    std::cin >> n;
    return n;
}
// 6
Matrix copy(const Matrix& matrix1)
{
    Matrix matrix2 = newMatrix(matrix1.n, matrix1.m);
    for(int i = 0; i < matrix1.n; ++i)
    {
        for (int j = 0; j < matrix1.m; ++j)
        {
            matrix2.matrix[i][j] = matrix1.matrix[i][j];
        }
    }
    return matrix2;
}
// 7
Matrix transpose(const Matrix& matrix1)
{
    Matrix matrix2 = newMatrix(matrix1.m, matrix1.n);
    for (int i = 0; i < matrix1.n; ++i)
        for (int j = 0; j < matrix1.m; ++j)
            matrix2.matrix[i][j] = matrix1.matrix[j][i];
    return matrix2;
}
// 8
// 9
float determinant (Matrix matrix)
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
// 10
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
// 11
Matrix mult(const Matrix& aMatrix, const Matrix& bMatrix)
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
// 12
bool equal(const Matrix& aMatrix, const Matrix& bMatrix)
{
    int number = 0;
    int inner = 0;
    if ((aMatrix.n == bMatrix.n) && (aMatrix.m == bMatrix.m))
    {
        for (int i = 0; i < aMatrix.m; ++i)
        {
            for (int j = 0; j < aMatrix.n; ++j)
            {
                if (aMatrix.matrix[j][i] == bMatrix.matrix[j][i])
                    ++number;
                else
                {
                    ++inner;
                    break;
                }
            }
            if (inner == 1)
                break;
        }
        if (number == (aMatrix.n * aMatrix.m))
            return true;
        else
            return false;
    }
    else
        return false;
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
    Matrix matrix = newMatrix(n, m);
    snake(matrix, 1, enterANumber);
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
    //deleteMatrix(matrixA);
    //deleteMatrix(matrixB);
    // 7
    n = 10;
    m = 10;
    Matrix matrix0 = newMatrix(n, m);
    Matrix matrixT = transpose(matrix0);
    deleteMatrix(matrix0);
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
    d = equal(matrixOne, matrixTwo);
    std::cout << d << std::endl;
    deleteMatrix(matrixOne);
    deleteMatrix(matrixTwo);
    return 0;
}
