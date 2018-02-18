#include <iostream>
#include <stdexcept>
#include "residue.hpp"

#define EXPECT_TRUE(x) if (!(x)) { throw std::logic_error(#x); }
#define EXPECT_FALSE(x) if ((x)) { throw std::logic_error(#x); }
#define EXPECT_EXCEPTION(x) try{ (x); throw std::logic_error(#x);
} catch(const std::runtime_error&) { }

int main()
{
    try
    {
        Residue a(1, 7);
        Residue b(0, 7);

        Residue c(a);
        c = b;

        EXPECT_TRUE(a == Residue(8, 7));
        EXPECT_TRUE(a == Residue(7 * 13 + 7 * 10 + 1, 7));

        EXPECT_TRUE(c == b);
        EXPECT_FALSE(c == a);

        EXPECT_FALSE(c != b);
        EXPECT_TRUE(c != a);

        EXPECT_TRUE(c < a);
        EXPECT_FALSE(c < b);

        EXPECT_TRUE(c <= a);
        EXPECT_TRUE(c <= b);

        EXPECT_TRUE(c >= b);
        EXPECT_FALSE(c > b);

        EXPECT_TRUE(c <= a);
        EXPECT_TRUE(c <= a);

        a += b;
        EXPECT_TRUE(a == Residue(1, 7));

        a += a;
        EXPECT_TRUE(a == Residue(2, 7));

        a -= a;
        EXPECT_TRUE(a == Residue(0, 7));

        EXPECT_TRUE(a++ == Residue(0, 7));
        EXPECT_TRUE(++a == Residue(2, 7));

        EXPECT_TRUE(a-- == Residue(2, 7));
        EXPECT_TRUE(--a == Residue(0, 7));
        EXPECT_TRUE(--a == Residue(6, 7));

        EXPECT_TRUE(~a == a);
        EXPECT_TRUE(-a == Residue(1, 7));

        EXPECT_TRUE(~(--a) == Residue(3, 7));

        a *= 10;
        EXPECT_TRUE(a == Residue(1, 7));

        a *= 10;
        EXPECT_TRUE(a == Residue(3, 7));

        a *= Residue(3, 7);
        EXPECT_TRUE(a == Residue(2, 7));

        a /= Residue(5, 7);
        EXPECT_TRUE(a == Residue(6, 7));

        Residue d = a * 3;
        EXPECT_TRUE(d == Residue(4, 7));

        d = 3 * d;
        EXPECT_TRUE(d == Residue(5, 7));

        EXPECT_EXCEPTION(a < Residue(5, 17));
        EXPECT_EXCEPTION(a == Residue(5, 17));
        EXPECT_EXCEPTION(a != Residue(5, 17));
        EXPECT_EXCEPTION(a >= Residue(5, 17));
        EXPECT_EXCEPTION(a *= Residue(5, 17));
        EXPECT_EXCEPTION(a -= Residue(5, 17));
        EXPECT_EXCEPTION(a += Residue(5, 17));
        EXPECT_EXCEPTION(a /= Residue(5, 17));

        a = Residue(5, 17);

        EXPECT_TRUE(a.Mod() == 17);
    }
    catch (const std::logic_error& e)
    {
        std::cout << "test failed! " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
