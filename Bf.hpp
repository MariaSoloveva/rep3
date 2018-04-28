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
    {
        boolean_function v(0, dimension);
        unsigned int inner = (unsigned int)(ldexp (1 , n));
        unsigned int k = 0;
        while (k != v.size())
        {
            for (size_t i = 0; i < inner; ++i)
            {
                v[k] = 0;
                ++k;
            }
            for (size_t j = 0; j < inner; ++j)
            {
                v[k] = 1;
                ++k;
            }
        }
        return v;
    }
    // тождественный ноль "от dimension переменных"
    static boolean_function zero(size_t dimension)
    {
        return boolean_function((1 << (1 << dimension)), dimension);
    }

    // тождественная единица "от dimension переменных"
    static boolean_function one(size_t dimension)
    {
        return boolean_function((1 << (1 << dimension)) - 1, dimension);
    }

    static boolean_function from_anf(std::vector<value_type> v);

    boolean_function() = default;
    // задает фунцию от n переменных. значение равно value
    // пример
    // пусть value = 14, т.е. 0...00001110 в двоичной системе
    // а n = 3
    // тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
    boolean_function(unsigned long long value, size_type n)
        : bf((unsigned int)(ldexp (1 , n)))
    {
        for (size_t i = bf.size(); i != 0; --i)
        {
            if (value % 2 != 0 && value > 0)
            {
                bf[i - 1] = 1;
                --value;
            }
            else
                bf[i - 1] = 0;
            value /= 2;
        }
    }

    // пусть table = "01110000"
    // тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
    boolean_function(const std::string& table)
        : bf(table.size())
    {
        for (size_t i = 0; i < table.size(); ++i)
        {
            if (table[i] == '0')
                bf[i] = 0;
            else
                bf[i] = 1;
        }
    }

    // пусть table = {true, false, false, true};
    // тогда АНФ boolean_function будет равна x + y + 1
    boolean_function(const std::vector<value_type>& table)
    {
        bf = table;
    }
    boolean_function(const std::initializer_list<bool> vars)
    {
        for (auto v : vars)
            bf.push_back(v);
    }

    boolean_function(const boolean_function& table)
        : bf(table.size())
    {
        std::copy(table.cbegin(), table.cend(), begin());
    }

    boolean_function& operator=(const boolean_function& rhs)
    {
        if (this != &rhs)
        {
            bf = rhs.bf;
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
        return *this;
    }

    // true если функции равны
    //  иначе false
    bool operator == (const boolean_function& rhs) const
    {
        return rhs.bf == bf;
    }

    // true если одна функция сравнима и больше или равна rhs
    // false если сравнима и меньше rhs
    // logic_error если фунции не сравнимы
    bool operator >= (const boolean_function& rhs) const
    {

    }

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
    bool operator()(const std::vector<bool>& vars) const
    {
        size_type inner = 0;
        size_type two = 1;
        for (size_t i = vars.size(); i != 0; --i)
        {
            inner += vars[i] * two;
            two *= 2;
        }
        return bf[inner];
    }
    bool operator()(const std::initializer_list<bool> vars) const
    {
        size_type inner = 0;
        size_type two = 1;
        std::initializer_list<bool>::iterator i = vars.end();
        while(i != vars.begin())
        {
            --i;
            inner += *i * two;
            two *= 2;
        }
        return bf[inner];
    }

    // T(x1, x2, ..., xN) - текущая функция
    // operator вернет новую функцию, которая равна композиции G = T(fs[0], fs[1], ..., fs[N-1])
    boolean_function operator()(const std::vector<boolean_function>& fs) const
    {
        boolean_function copy = *this;
        std::vector<bool> vars(fs.size());
        std::vector<bool> newfunc(fs[0].size());
        for (size_t i = 0; i < fs[0].size(); ++i)
        {
            for (size_t j = 0; j < fs.size(); ++j)
            {
                vars[j] = fs[j].bf[i];
            }
            newfunc[i] = copy(vars);
            vars.clear();
        }
        return boolean_function(newfunc);
    }
    boolean_function operator()(const std::initializer_list<boolean_function> vars) const
    {
        boolean_function copy = *this;
        std::vector<bool> var(vars.size());
        std::vector<bool> newfunc((*vars.begin()).size());
        for (size_t i = 0; i < (*vars.begin()).size(); ++i)
        {
            for (size_t j = 0; j < vars.size(); ++j)
            {
                var.push_back((*(vars.begin() + j)).bf[i]);
            }
            newfunc.push_back(copy(var));
            var.clear();
        }
        return boolean_function(newfunc);
    }

    bool is_monotone() const;
    bool is_symmetric() const;
    bool is_linear() const;
    bool is_T1() const
    {
        return bf[bf.size() - 1] == 1;
    }
    bool is_T0() const
    {
        return bf[0] == 0;
    }
    bool is_balanced() const //  равновесная ли
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
            if (bf[i] == 1)
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

