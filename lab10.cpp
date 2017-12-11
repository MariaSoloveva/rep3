#include<algorithm>
#include <iostream>
#include "forward_list.hpp"
#include"queue.hpp"
#include"stack.hpp"

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
    Queue* q = initQueue();
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);
    print(q);
    std::cout << std::endl;
    pop(q);
    print(q);
    destroyQ(&q);
    return 0;
}
