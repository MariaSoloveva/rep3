#include <iostream>
#include "vector.hpp"

int main()
{
    vector<int> a(10, 0);
    for (size_t i = 0; i < a.size(); ++i)
    {
        a[i] = i;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    a.pop_back();
    a.insert(3, 4444);
    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    /*vector<int> a1(10, 0);
    const vector<int> b(10, 0);
    vector<int> c;
    c = a;
    std::cout << a.at(0) << " " << b.at(1)  << " " << b.at(b.size() - 1)<< std::endl;
    std::cout << a[1] << " " << b[1] << std::endl;
    a[1] = 11;
    std::cout << a[1] << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << a.back() << " " << a.front() << std::endl;
    std::cout << a.empty() << std::endl;
    a.swap(a1);
    a.clear();
    for (size_t i = 0; i < a.size(); ++i)
    {
        a[i] = i;
        std::cout << a[i] << " ";
    }*/
    return 0;
}
