#include <cstring>
#include <vector>
#include <cmath>
#include <stdexcept>

class boolean_function
{
public:
    using value_type = bool;
    using size_type = size_t;
    using reference = std::vector<value_type>::reference;
    using const_reference = std::vector<value_type>::const_reference;

    using iterator = typename std::vector<value_type>::iterator;
    using const_iterator = typename std::vector<value_type>::const_iterator;
private:
    std::vector<value_type> bf;
public:

    // возвращает функцию которая равна xn с размерностью dimension
    // пример 1
    // n = 0
    // dimension = 3
    // вернется функция "01010101"
    // пример 2
    // n = 1
    // dimension = 4
    // вернется функция "0011001100110011"
    static boolean_function var(size_t n, size_t dimension)
        : bf((unsigned int)pow(2, dimension))
    {

    }
    // тождественный ноль "от dimension переменных"
    static boolean_function zero(size_t dimension)
            : bf((unsigned int)pow(2, dimension))
    {

    }

    // тождественная единица "от dimension переменных"
    static boolean_function one(size_t dimension);

    static boolean_function from_anf(std::vector<value_type> v);

    boolean_function() = default;
    // а n = 3
    // тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
    boolean_function(unsigned long long value, size_type n);

    // пусть table = "01110000"
    // тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
    boolean_function(const std::string& table);

    // пусть table = {true, false, false, true};
    // тогда АНФ boolean_function будет равна x + y + 1
    boolean_function(const std::vector<value_type>& table);
    boolean_function(const std::initializer_list<bool> vars);

    boolean_function(const boolean_function& table)
        : bf(table.size())
    {
        std::copy(table.cbegin(), table.cend(), begin());
    }

    boolean_function& operator=(const boolean_function& rhs)
    {
        if (this != &rhs)
        {
            bf.clear();
            std::copy(rhs.cbegin(), rhs.cend(), begin());
        }
        return *this;
    }
    // сложение по модулю 2
    // если разное количество переменных - исключение
    boolean_function& operator += (const boolean_function& rhs)
    {
        if (rhs.size() != size())
        {
            throw std::invalid_argument("different number of variables");
        }
        for (size_t i = 0; i < size(); ++i)
            bf[i] = (bf[i] + rhs[i]) % 2;
        return *this;
    }

    // конъюнкция
    // если разное количество переменных - исключение
    boolean_function& operator *= (const boolean_function& rhs)
    {
        if (rhs.size() != size())
        {
            throw std::invalid_argument("different number of variables");
        }
        for (size_t i = 0; i < size(); ++i)
            bf[i] = bf[i] * rhs[i];
        return *this;
    }

    // дизъюнкция
    // если разное количество переменных - исключение
    boolean_function& operator |= (const boolean_function& rhs)
    {
        if (rhs.size() != size())
        {
            throw std::invalid_argument("different number of variables");
        }
        for (size_t i = 0; i < size(); ++i)
            bf[i] = bf[i] + rhs[i];
        return *this;
    }

    // побитовое отрицание
    boolean_function operator ~ ()
    {
        for (size_t i = 0; i < size(); ++i)
        {
            bf[i] = (bf[i] + 1) % 2;
        }
    }

    // true если функции равны
    //  иначе false
    bool operator == (const boolean_function& rhs) const
    {
        for (size_t i = 0; i < size(); ++i)
        {
            if (bf[i] != rhs[i])
                return false;
        }
        return true;
    }

    // true если одна функция сравнима и больше или равна rhs
    // false если сравнима и меньше rhs
    // logic_error если фунции не сравнимы
    bool operator >= (const boolean_function& rhs) const;

    reference operator[](size_type ind)
    {
        return bf[ind];
    }
    const_reference operator[](size_type ind) const
    {
        return bf[ind];
    }

    reference at(size_type ind)
    {
        return bf.at(ind);
    }
    const_reference at(size_type ind) const
    {
        return bf.at(ind);
    }
    iterator begin()
    {
        return bf.begin();
    }
    iterator end()
    {
        return bf.end();
    }
    const_iterator cbegin() const
    {
        return bf.cbegin();
    }
    const_iterator cend() const
    {
        return bf.cend();
    }
    // длина столбца функции
    size_type size() const throw()
    {
        return bf.size();
    }

    // количество переменных
    size_type dimension() const throw()
    {
        size_type size = bf.size();
        size_type inner = 0;
        while (size != 1)
        {
            size /= 2;
            ++inner;
        }
        return inner;
    }

    // возвращает значение функции
    // пусть boolean_function задает функцию f(x, y, z)
    // тогда функция вернет f(vars[0], vars[1], vars[2])
    bool operator()(const std::vector<bool>& vars) const;
    bool operator()(const std::initializer_list<bool> vars) const;


    // T(x1, x2, ..., xN) - текущая функция
    // operator вернет новую функцию, которая равна композиции G = T(fs[0], fs[1], ..., fs[N-1])
    boolean_function operator()(const std::vector<boolean_function>& fs) const;
    boolean_function operator()(const std::initializer_list<boolean_function> vars) const;

    bool is_monotone() const;
    bool is_symmetric() const;
    bool is_linear() const;
    bool is_T1() const;
    bool is_T0() const;
    bool is_balanced() const //равновесная ли
    {
        size_t inner1 = 0;
        size_t inner0 = 0;
        for (size_t i = 0; i < bf.size(); ++i)
        {
            if (bf[i] == 1)
                ++inner1;
            else
                ++inner0;
        }
        return inner0 == inner1;
    }
    size_t weight() const
    {
        size_t inner = 0;
        for (size_t i = 0; i < bf.size(); ++i)
        {
            if (bf[i] == 0)
                ++inner;
        }
        return inner;
    }

    bool is_functionally_complete_system() const
    {
        return !(is_monotone() || is_symmetric() || is_linear() || is_T1() || is_T0() || is_balanced());
    }

    // Возвращает АНФ функции
    std::vector<value_type> anf() const;
};

// пусть boolean_function представляет из себя функцию "01110000"
// тогда get_polynom вернет строку "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
std::string get_polynom(const boolean_function& a);

boolean_function operator + (const boolean_function& a, const boolean_function& b)
{
    boolean_function aCopy(a);
    aCopy += b;
    return aCopy;
}

boolean_function operator * (const boolean_function& a, const boolean_function& b)
{
    boolean_function aCopy(a);
    aCopy *= b;
    return aCopy;
}

boolean_function operator | (const boolean_function& a, const boolean_function& b)
{
    boolean_function aCopy(a);
    aCopy |= b;
    return aCopy;
}

bool operator != (const boolean_function& a, const boolean_function& b)
{
    return !(a == b);
}
