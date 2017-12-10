#include<algorithm>
#include <iostream>
#include "forward_list.hpp"

int main()
{
    ForwardList* l = initList();
    pushBack(l, 1);
    pushBack(l, 2);
    pushBack(l, 3);
    pushFront(l, -1);
    pushFront(l, -2);
    pushFront(l, -3);
    print(l);
    std::cout << std::endl;
    popFront(l);
    insertAfter(l, l->Head, 100);
    print(l);
    std::cout << std::endl;
    eraseAfter(l, l->Head);
    print(l);
    reverse(l);
    std::cout << std::endl;
    print(l);
    destroyList(&l);
    return 0;
}
