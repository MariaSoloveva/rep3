#include <cmath>
#include <iostream>

int main()
{
    std::pair<char, int> p1;
    p1.first = 'e';
    p1.second = 4;
    std::cout << " What chess piece? " << std::endl;
    char a;
    std::cin >> a;
    std::cout << " Initial coordinate? " << std::endl;
    std::pair<char, int> p2;
    char b;
    std::cin >> b;
    p2.first = b;
    int c = 0;
    std::cin >> c;
    p2.second = c;
    std::cout << " Next coordinate? " << std::endl;
    std::pair<char, int> p3;
    std::cin >> a;
    std::cin >> c;
    p1.first = a;
    p1.second = c;
    if (a = 'R')
    {
        if (((p1.first == p2.first) || (p1.second == p2.second)) &&
            ((p3.first != p1.first) && (p3.second != p1.second)) &&
            (((p1.first >= p2.first) || (p1.second >= p2.second)) ||
             ((p1.first <= p2.first) || (p1.second <= p2.second))))
        {
            std::cout << " True " << std::endl;
        }
        else
        {
            std::cout << " False " << std::endl;
        }
    }
    if (a =='B')
    {
        if (((std::abs(p1.first - p2.first) == std::abs(p1.second - p2.second)) &&
             ((p3.first != p1.first) || (p3.second != p1.second)) &&
             (((p2.first - p1.first > 0) || (p2.second - p1.second >0)) ||
              ((p2.first - p1.first < 0) || (p2.second - p1.second < 0)))))
        {
            std::cout << " True " << std::endl;
        }
                else
        {
            std::cout << " False " << std::endl;
        }
    }
    if (a == 'Q')
    {
        if ((((p1.first == p2.first) || (p1.second == p2.second)) &&
            ((p3.first != p1.first) && (p3.second != p1.second)) &&
            (((p1.first >= p2.first) || (p1.second >= p2.second)) ||
             ((p1.first <= p2.first) || (p1.second <= p2.second)))) &&
        ((((std::abs(p1.first - p2.first) == std::abs(p1.second - p2.second)) &&
           ((p3.first != p1.first) || (p3.second != p1.second)) &&
           (((p2.first - p1.first > 0) || (p2.second - p1.second >0)) ||
            ((p2.first - p1.first < 0) || (p2.second - p1.second < 0)))))))
        {
            std::cout << " True " << std::endl;
        }
        else
        {
            std::cout << " False " << std::endl;
        }
    }
    if (a = 'p')
    {
        if (((p1.second == p2.second + 1) && ((p3.first != p1.first) && (p3.second != p1.second)) &&
                                           ((p2.second - p1.second) > 0)))
        {
            std::cout << " True " << std::endl;
        }
        else
        {
            std::cout << " False " << std::endl;
        }
    }

}
