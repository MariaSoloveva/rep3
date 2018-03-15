#include <algorithm>
#include <iostream>


class Integer
{
    int Number;
 public:
    Integer() = default;
    ~Integer() = default;
    Integer(const int value)
        : Number(value)
    {}
    Integer(const Integer& a)
        : Number(a.Number)
    {}
    Integer& operator = (const Integer& a)
    {
        Number = a.Number;
    }
    Integer& operator = (const int& a)
    {
        Number = a;
    }
    Integer& operator += (const Integer& a)
    {
        if (Number + a.Number > INT16_MAX)
            throw std::invalid_argument("It's imposible to find sum ");
        Number += a.Number;
        return *this;
    }
    Integer& operator += (const int& a)
    {
        if (Number + a > INT16_MAX)
            throw std::invalid_argument("It's imposible to find sum ");
        Number += a;
        return *this;
    }
    Integer& operator -= (const Integer& a)
    {
        if (Number - a.Number < INT16_MIN)
            throw std::invalid_argument("It's imposible to find difference ");
        Number -= a.Number;
        return *this;
    }
    Integer& operator -= (const int& a)
    {
        if (Number - a < INT16_MIN)
            throw std::invalid_argument("It's imposible to find sum ");
        Number -= a;
        return *this;
    }
    Integer& operator *= (const int& a)
    {
        if (Number * a > INT16_MAX)
            throw std::invalid_argument("It's imposible to obtain ");
        Number *= a;
        return *this;
    }
    Integer& operator *= (const Integer& a)
    {
        if (Number * a.Number > INT16_MAX)
            throw std::invalid_argument("It's imposible to obtain ");
        Number *= a.Number;
        return *this;
    }
    Integer& operator /= (const int& a)
    {
        if (a == 0)
            throw std::invalid_argument("It's imposible to obtain ");
        Number /= a;
        return *this;
    }
    Integer& operator /= (const Integer& a)
    {
        if (a.Number == 0)
            throw std::invalid_argument("It's imposible to obtain ");
        Number /= a.Number;
        return *this;
    }
    Integer& operator %= (const int& a)
    {
        if (a == 0)
            throw std::invalid_argument("It's imposible to find residue");
        Number %= a;
        return *this;
    }
    Integer& operator %= (const Integer& a)
    {
        if (a.Number == 0)
            throw std::invalid_argument("It's imposible to find residue ");
        Number %= a.Number;
        return *this;
    }
    Integer& operator ^= (const int& a)
    {
        if (a < 0)
            throw std::invalid_argument("It's imposible to find degree ");
        if (a == 0)
        {
            Number = 1;
            return *this;
        }
        for (int i = 1; i < a; ++i)
        {
            if (Number * a > INT16_MAX)
                throw std::invalid_argument("It's imposible to find degree ");
            Number *= a;
        }
        return *this;
    }
    Integer& operator ^= (const Integer& a)
    {
        if (a.Number < 0)
            throw std::invalid_argument("It's imposible to find degree ");
        if (a.Number == 0)
        {
            Number = 1;
            return *this;
        }
        for (int i = 1; i < a.Number; ++i)
        {
            if (Number * a.Number > INT16_MAX)
                throw std::invalid_argument("It's imposible to find degree ");
            Number *= a.Number;
        }
        return *this;
    }
    bool operator ==(const Integer& a)
    {
        return (a.Number == Number);
    }
    bool operator < (const Integer& a)
    {
        return (Number < a.Number);
    }
    friend std::ostream& operator<<(std::ostream& out, const Integer& a);
};
Integer operator+(const Integer& a, const Integer& b)
{
    Integer c(a);
    c += b;
    return c;
}
Integer operator+(const int& a, const Integer& b)
{
    Integer c(b);
    c += a;
    return c;
}
Integer operator+(const Integer& a, const int& b)
{
    Integer c(a);
    c += b;
    return c;
}
Integer operator-(const Integer& a, const Integer& b)
{
    Integer c(a);
    c -= b;
    return c;
}
Integer operator-(const int& a, const Integer& b)
{
    Integer c(b);
    c -= a;
    return c;
}
Integer operator-(const Integer& a, const int& b)
{
    Integer c(a);
    c -= b;
    return c;
}
Integer operator*(const Integer& a, const Integer& b)
{
    Integer c(a);
    c *= b;
    return c;
}
Integer operator*(const int& a, const Integer& b)
{
    Integer c(b);
    c *= a;
    return c;
}
Integer operator*(const Integer& a, const int& b)
{
    Integer c(a);
    c *= b;
    return c;
}
Integer operator/(const Integer& a, const Integer& b)
{
    Integer c(a);
    c /= b;
    return c;
}
Integer operator/(const int& a, const Integer& b)
{
    Integer c(b);
    c /= a;
    return c;
}
Integer operator/(const Integer& a, const int& b)
{
    Integer c(a);
    c /= b;
    return c;
}
Integer operator%(const Integer& a, const Integer& b)
{
    Integer c(a);
    c %= b;
    return c;
}
Integer operator%(const int& a, const Integer& b)
{
    Integer c(b);
    c %= a;
    return c;
}
Integer operator%(const Integer& a, const int& b)
{
    Integer c(a);
    c %= b;
    return c;
}
Integer operator^(const Integer& a, const Integer& b)
{
    Integer c(a);
    c /= b;
    return c;
}
Integer operator^(const Integer& a, const int& b)
{
    Integer c(a);
    c /= b;
    return c;
}
bool operator !=(const Integer& a, const Integer& b)
{
    Integer c(a);
    return !(c == b);
}
bool operator > (const Integer& a, const Integer& b)
{
    Integer c(a);
    return !(c < b) && !(c == b);
}
bool operator >= (const Integer& a, const Integer& b)
{
    Integer c(a);
    return c > b || c == b;
}

bool operator <= (const Integer& a, const Integer& b)
{
    Integer c(a);
    return c < b || c == b;
}
std::ostream& operator<<(std::ostream& out, const Integer& a)
{
    return out << a.Number;
}
int main()
{
    Integer num1;
    Integer num2(32);
    Integer num3(16);
    num1 = num3;
    std::cout << " num1 : " << num1 << std::endl;
    num1 += 2;
    std::cout << "num1 += 2 : " << num1 << std::endl;
    num1 += num2;
    std::cout << "num1 += num2 : " << num1 << std::endl;
    num1 = 2;
    std::cout << "num1 = 2 : " << num1 << std::endl;
    num3 /= num1;
    std::cout << "num3 /= num1 : " << num1 << std::endl;
    num3 ^= num1;
    std::cout << "num3 ^= num1 : " << num1 << std::endl;
    num3 -= num1;
    std::cout << "num3 == num1 : " << (num3 == num1) << std::endl;
    std::cout << "num3 == num3 : " << (num3 == num3) << std::endl;
    std::cout << "num3 != num1 : " << (num3 != num1) << std::endl;
    std::cout << "num3 != num3 : " << (num3 != num3) << std::endl;
    std::cout << "num3 > num1 : " << (num3 > num1) << std::endl;
    std::cout << "num3 < num1 : " << (num3 < num1) << std::endl;
    std::cout << "num3 < num3 : " << (num3 < num3) << std::endl;
    std::cout << "num3 >= num1 : " << (num3 >= num1) << std::endl;
    std::cout << "num3 <= num3 : " << (num3 <= num3) << std::endl;
    std::cout << "num3 - num3 : " << (num3 - num3) << std::endl;
    std::cout << "num3 + num3 : " << (num3 + num3) << std::endl;
    std::cout << "num3 * num3 : " << (num3 * num3) << std::endl;
    std::cout << "num3 / num3 : " << (num3 / num3) << std::endl;
    return 0;
}
