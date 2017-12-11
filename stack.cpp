#include<algorithm>
#include <iostream>
#include"stack.hpp"

Stack* initStack()
{
    Stack* st = new Stack();
    st->Head = nullptr;
    return st;
}
void destroyS(Stack** st)
{
    Stack* stack = *st;
    Stack::Node* tail = stack->Tail;
    while (tail)
    {
        Stack::Node* tmp = tail->Next;
        delete tail;
        tail = tmp;
    }
    delete stack;
    *st = nullptr;
}
Stack::Node* createNodeForStack(const Stack::value_type& data, Stack::Node* next)
{
    Stack::Node* node = new Stack::Node();
    node->Data = data;
    node->Next = next;
    return node;
}
Stack::Node* push(Stack* const st, const Stack::value_type& data)
{
    Stack::Node* node = createNodeForStack(data, st->Head);
    Stack::Node* head = st->Head;
    st->Head = node;
    st->Head->Next = head;
    return node;
}
void pop(Stack* const st)
{
    Stack::Node* next = 0;
    if (st->Head)
    {
        next = st->Head->Next;
        delete st->Head;
        st->Head = next;
    }
}
Stack::Node* top(Stack* const st)
{
    return st->Head;
}
