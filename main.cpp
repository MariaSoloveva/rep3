#include <iostream>
#include "set.hpp"

int main()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(5);
    s1.insert(3);
    s1.insert(2);
    s1.insert(8);
    s1.insert(0);
    s1.insert(15);
    s1.insert(20);
    s1.insert(11);
    s1.insert(22);
    s1.insert(19);
    std::cout<< s1.size() <<std::endl;
    std::cout<< s1.empty() <<std::endl;
    s1.find(9);
    std::cout<< s1.has(9) <<std::endl;
    //  s1.erase(s1.find(19));
    return 0;
}
