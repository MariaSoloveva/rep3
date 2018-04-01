#include <cstdio>
#include <cstring>
#include <iterator>
#include <stdexcept>

template <class T>
class vector
{
    T* Vector;
    size_t N;
    size_t Pow;
public:
    class Iterator
            : public std::iterator<std::random_access_iterator_tag, T>
    {
     private:
        T * ptr;
     public:
        explicit Iterator(T* p)
                : ptr(p)
        { }

        T& operator*()
        {
            return *ptr;
        }

        T* operator->()
        {
            return ptr;
        }

        Iterator& operator++()
        {
            ++ptr;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator it(ptr);
            ++ptr;
            return it;
        }
        Iterator& operator+=(size_t n)
        {
            ptr += n;
            return *this;
        }
        Iterator& operator-=(size_t n)
        {
            ptr -= n;
            return *this;
        }

        Iterator& operator--()
        {
            --ptr;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator it(ptr);
            --ptr;
            return it;
        }

        bool operator==(Iterator it)
        {
            return ptr == it.ptr;
        }

        bool operator<(Iterator it)
        {
            return ptr < it.ptr;
        }

        bool operator<=(Iterator it)
        {
            return this->operator==(it) || this->operator<(it);
        }

        bool operator>(Iterator it)
        {
            return !(this->operator==(it) || this->operator<(it));
        }

        bool operator>=(Iterator it)
        {
            return !this->operator<(it);
        }

        bool operator!=(Iterator it)
        {
            return !(this->operator==(it));
        }
    };
    using value_type = T;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = T*;
    using const_pointer = const T*;
    using iterator = Iterator;
    using const_iterator = const Iterator;
    vector() = default;
    ~vector() = default;
    vector(const vector& vec)
            : N(vec.N)
            , Pow(vec.Pow)
            , Vector(new T[Pow])
    {
        memcpy(Vector, vec.Vector, Pow * sizeof(Vector[0]));
    }
    vector(size_t n, const T& v)
            : N(n)
    {
        Pow = 1;
        while (Pow < n)
            Pow *= 2;
        Vector = new T[Pow];
        memset(Vector, v, N * sizeof(v));
    }
    vector& operator=(const vector& vec)
    {
        if (this != &vec)
        {
            delete[] Vector;
            N = vec.N;
            Pow = vec.Pow;
            Vector = new T[Pow];
            memcpy(Vector, vec.Vector, N * sizeof(Vector[0]));
        }
        return *this;
    }
    reference operator[](size_t input)
    {
        return Vector[input];
    }
    const_reference operator[](size_t input) const
    {
        return Vector[input];
    }
    size_type size() const noexcept
    {
        return N;
    }
    reference at(size_t pos)
    {
        if (pos < size())
            return Vector[pos];
        throw std::out_of_range("out_of_range");
    }
    const_reference at(size_t pos) const
    {
        if (pos < size())
            return Vector[pos];
        throw std::out_of_range("out_of_range");
    }
    reference front()
    {
        return Vector[0];
    }

    const_reference front() const
    {
        return Vector[0];
    }

    reference back()
    {
        return Vector[size() - 1];
    }

    const_reference back() const
    {
        return Vector[size() - 1];
    }
    iterator begin()
    {
        return iterator(Vector);
    }

    const_iterator begin() const
    {
        return const_iterator(Vector);
    }
    iterator end()
    {
        return iterator(Vector + size());
    }
    const_iterator end() const
    {
        return const_iterator(Vector + size());
    }
    pointer data() noexcept
    {
        return &front();
    }
    const_pointer data() const noexcept
    {
        return &front();
    }
    bool empty() const
    {
        return size() == 0;
    }
    void reserve(size_type size1)
    {
        if (size1 > Pow)
            throw std::length_error("Length error");
    }
    size_type capacity() const
    {
        return Pow;
    }
    void clear()
    {
        for(int index = 0; index < N; index++)
            Vector[index] = 0;
    }
    void insert(size_type pos, const T& value)
    {
        if (N + 1 > Pow)
        {
            T* result = new T[++this->N];
            for(int index = N; index != -1; --index)
            {
                result[index + 1] = Vector[index];
                if (pos == index)
                    result[index + 1] = value;
            }
            delete [] Vector;
            Vector = result;
            delete [] result;
        }
        else
        {
            for(int index = N - 1; index != -1; --index)
            {
                Vector[index + 1] = Vector[index];
                if (pos == index)
                    Vector[index + 1] = value;
            }
        }
    }
    void push_back(const T& value)
    {
        if (N + 1 > Pow)
        {
            T* result = new T[++this->N];
            memcpy(result, Vector, Pow * sizeof(Vector[0]));
            result[N] = value;
            delete[] Vector;
            Vector = result;
            delete[] result;
        }
        else
        {
            Vector[N] = value;
        }
        ++N;
    }
    void pop_back()
    {
        Vector[size() - 1] = 0;
        --N;
    }
    void swap(vector& oth)
    {
        for (size_type i = 0; i < size(); ++i)
        {
            std::swap(oth[i], Vector[i]);
        }
    }
};
template<class T>
bool operator==(const vector<T>& a, const vector<T>& b)
{
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

template<class T>
bool operator!=(const vector<T>& a, const vector<T>& b)
{
    return !(a == b);
}
