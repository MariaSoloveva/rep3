#ifndef MATRIX_INCLUDE
#define MATRIX_INCLUDE

struct Matrix
{
    float ** matrix;
    int n;
    int m;
};

Matrix newMatrix(int, int);
void deleteMatrix(Matrix&);
void snake(Matrix&);
Matrix copy(const Matrix&);
Matrix transpose(const Matrix&);
Matrix inverse(const Matrix&);
float determinant(const Matrix&);
Matrix ones(int);
Matrix operator*(const Matrix&, const Matrix&);
bool operator==(const Matrix&, const Matrix&);

#endif // MATRIX_INCLUDE