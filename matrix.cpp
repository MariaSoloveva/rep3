template <class T>
class Matrix
{
public:
    class Row
    {
        T* Rows;
        size_t M;
    public:
        Row()
        {
            Rows = nullptr;
            M = 0;
        }
        Row(size_t a)
        {
            Rows = new T[a];
            M = a;
        }
        T& operator[](size_t index)
        {
            return Rows[index];
        }
        T operator[](size_t index) const
        {
            return Rows[index];
        }
        Row(const Row& a)
        {
            Rows = new T[a.M];
            std::copy(a.Rows[0], a.Rows[a.M - 1], this);
            M = a.M;
        }
        Row& operator=(const Row& a)
        {
            std::copy(a.Rows[0], a.Rows[a.M - 1], this);
            return *this;
        }
    };
    Matrix(size_t n, size_t m)
    {
        MatrixNM = new Row[m];
        for(size_t i = 1; i < n; ++i)
            MatrixNM[i] = new Row(m);
    }

    /// создает матрицу из одномерного массива
    /// {1, 2, 3, 4, 5, 6, 7, 8}, n = 4, m = 2
    /// Матрица будет иметь две строки и четыре столбца:
    /// 1 2 3 4
    /// 5 6 7 8
    /*Matrix(const std::vector<T>& vecIn, size_t n, size_t m)
    {
        MatrixNM = new T*[m];
        int distance = 0;
        for(int i = 0; i < n; ++i)
        {
            MatrixNM[i] = new T[m];
            memset(MatrixNM[i], 0, sizeof(MatrixNM[i][0])* m);
            std::copy(vecIn.begin() + distance,vecIn.begin() + distance + m, MatrixNM[i]);
            distance += m;
        }
    }

    Matrix(const Matrix<T>& m)
    {
        MatrixNM = new T*[m.NumCols()];
        for(int i = 0; i < m.NumRows(); ++i)
        {
            MatrixNM[i] = new T[m.NumCols()];
            memset(MatrixNM[i], 0, sizeof(MatrixNM[i][0])* m.NumCols());
            //std::copy(MatrixNM[i], m[i], m.NumCols());
        }
        for(size_t i = 0; i < m.NumRows(); ++i)
        {
            for(size_t j = 0; j < m.NumCols(); ++j)
                std::cout << MatrixNM[i][j] << " ";
            std::cout << std::endl;
        }
    }*/
    Matrix<T>& operator=(const Matrix<T>&);

    size_t NumRows() const
    {
        return N;
    }
    size_t NumCols() const
    {
    }

    Matrix<T>& operator+=(const Matrix<T>& b)
    {
        //if ((N == b.NumRows()) && (M == b.NumCols()))
        //{
            for (int i = 0; i < N; ++i)
            {
                //for (int j = 0; j < M; ++j)
                     //MatrixNM[i][j] += b[i][j];
            }
        //}
        return *this;
    }
    Matrix<T>& operator-=(const Matrix<T>&);
    Matrix<T>& operator*=(const Matrix<T>&);
    Matrix<T>& operator*=(const std::vector<T>&);
    Matrix<T>& operator*=(T);

    Matrix<T> Transpose() const;
    Matrix<T> Inverse() const;
    T Determinant() const;

    /*const Row& operator[](size_t index) const
    {
        return MatrixNM[index];
    }
    Row& operator[](size_t index)
    {
        return MatrixNM[index];
    }*/

private:
    Row** MatrixNM;
    size_t N;
    //Polynomial<T> CharacteristicEquation() const;
};


template<class T>
bool operator==(const Matrix<T>&, const Matrix<T>&)
{

}

template<class T>
bool operator!=(const Matrix<T>& a, const Matrix<T>& b)
{
    return !(a == b);
}

template<class T>
Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b)
{
    return a += b;
}

template<class T>
Matrix<T> operator-(const Matrix<T>& a, const Matrix<T>& b)
{
    return a -= b;
}

template<class T>
Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b)
{
    return a *= b;
}

template<class T>
Matrix<T> operator*(const Matrix<T>& a, T b)
{
    return a *= b;
}

template<class T>
Matrix<T> operator*(T b, const Matrix<T>& a)
{
    return a *= b;
}

int main()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(0, 9);
    std::vector<int> v1(10), v2(10), v3(10);
    std::generate(v1.begin(), v1.end(), std::bind(dis, std::ref(mt)));
    //std::generate(v2.begin(), v2.end(), std::bind(dis, std::ref(mt)));
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    Matrix<int> m(3, 5);
    //Matrix<int> m(v1, 2, 5);
    //Matrix<int> m1(v1, 2, 5);;
    //m += m1;
    return 0;
