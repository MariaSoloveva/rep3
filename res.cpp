#include <iostream>
#include "residue.hpp"

Residue::Residue(ui64 a, ui64 p)
{
    Number = a % p;
    N = p;
}
Residue::Residue(const Residue& a)
{
    Number = a.Number;
    N = a.Mod();
}
Residue& Residue::operator=(const Residue& a)
{
    Number = a.Number;
    N = a.Mod();
}
/*Residue::~Residue()
{
    delete Number;
}*/
bool Residue::operator == (Residue b) const
{
    if (Mod() == b.Mod())
        return Number == b.Number;
    else
        throw std::runtime_error("the residues have different modules");
}
bool Residue::operator < (Residue b) const
{
    if (Mod() == b.Mod())
        return Number < b.Number;
    else
        throw std::runtime_error("the residues have different modules");
}
Residue& Residue::operator += (Residue b)
{
    if (Mod() == b.Mod())
    {
        Number += b.Number;
        Number = Number % Mod();
        return *this;
    }
    else
        throw std::runtime_error("the residues have different modules");
}
Residue& Residue::operator -= (Residue b)
{
    if (Mod() == b.Mod())
    {
        Number -= b.Number;
        Number = Number % Mod();
        return *this;
    }
    else
        throw std::runtime_error("the residues have different modules");
}
Residue& Residue::operator *= (Residue b)
{
    if (Mod() == b.Mod())
    {
        Number = (Number * b.Number) % Mod();
        return *this;
    }
    else
        throw std::runtime_error("the residues have different modules");
}
Residue& Residue::operator *= (ui64 b)
{
    Number *= b;
    Number = Number % Mod();
    return *this;
}
Residue& Residue::operator /= (Residue b)/////////////////////////////////////////
{
    if (Mod() == b.Mod())
    {
        Number = (Number * (~b).Number) % Mod();
        return *this;
    }
    else
        throw std::runtime_error("the residues have different modules");
}
Residue Residue::operator ++(int b)
{
    Residue s(Number, N);
    Number = (Number + 1) % Mod();
    return s;
}
Residue& Residue::operator ++()
{
    Number = (++Number) % Mod();
    return *this;
}
Residue Residue::operator --(int b)
{
    Residue s (Number, Mod());
    --Number;
    return s;
}
Residue& Residue::operator --()
{
    if (Number == 0)
        Number += Mod() - 1;
    else
        Number--;
    return *this;
}
// обратный по умножению
// если P составное - бросить исключение
Residue Residue::operator ~ () const
{
    for (ui64 i = 0; i < Mod(); ++i)
    {
        if ((i * Number) % Mod() == 1)
        {
            Residue s(i, Mod());
            return s;
        }
    }
}

Residue Residue::operator - () const
{
    ui64 newNum = -Number;
    newNum += Mod();
    Residue s(newNum, Mod());
    return s;
}

Residue Residue::operator ^= (ui64 b) const
{
    ui64 num = Number;
    for (int i = 0; i < b; ++i)
    {
        num *= Number;
    }
    Residue s (num % Mod(), Mod());
    return s;
}
ui64 Residue::Mod() const
{
    return N;
}

Residue operator + (Residue a, Residue b)
{
    return a += b;
}
Residue operator - (Residue a, Residue b)
{
    return a -= b;
}
Residue operator * (Residue a, ui64 b)
{
    return a *= b;
}
Residue operator * (ui64 a, Residue b)
{
    return b *= a;
}
Residue operator * (Residue a, Residue b)
{
    return a *= b;
}
Residue operator / (Residue a, Residue b)
{
    return a /= b;
}
Residue operator ^ (Residue a, ui64 b)
{
    return a ^= b;
}
bool operator != (Residue a, Residue b)
{
    return !(a == b);
}
bool operator > (Residue a, Residue b)
{
    return ((b < a) && !(a == b));
}
bool operator >= (Residue a, Residue b)
{
    return (a > b) || (a == b);
}
bool operator <= (Residue a, Residue b)
{
    return (a < b) || (a == b);
}
