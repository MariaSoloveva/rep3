#include<algorithm>
#include <iostream>
#include "forward_list.hpp"

ForwardList::Node* createNode(const ForwardList::value_type& data, ForwardList::Node* next)
{
    ForwardList::Node* node = new ForwardList::Node();
    node->Data = data;
    node->Next = next;
    return node;
}
void destroyNode(ForwardList::Node** ptr)
{
    ForwardList::Node* node = *ptr;
    delete node;
    *ptr = nullptr;
}
ForwardList* initList()
{
    ForwardList* ls = new ForwardList();
    ls->Head = nullptr;
    return ls;
}
void destroyList(ForwardList** ls)
{
    ForwardList* list = *ls;
    ForwardList::Node* head = list->Head;
    while (head)
    {
        ForwardList::Node* tmp = head->Next;
        delete head;
        head = tmp;
    }
    delete list;
    *ls = nullptr;
}
ForwardList::Node* pushFront(ForwardList* const list, const ForwardList::value_type & data)
{
    ForwardList::Node* node = createNode(data, list->Head);
    ForwardList::Node* head = list->Head;
    list->Head = node;
    list->Head->Next = head;
    return node;
}
ForwardList::Node* pushBack(ForwardList* const list, const ForwardList::value_type & data)
{
    ForwardList::Node* node = createNode(data, nullptr);
    if (list->Tail)
        list->Tail->Next = node;
    list->Tail = node;
    if (list->Head == nullptr)
        list->Head = node;
    return node;
}

size_t size(const ForwardList* const list)
{
    size_t size = 0;
    ForwardList::Node* head = list->Head;
    while (head)
    {
        ++size;
        head = head->Next;
    }
    return size;
}
ForwardList::Node* insertAfter(ForwardList* const list, ForwardList::Node* const where,
                               const ForwardList::value_type& data)
{
    ForwardList::Node* newNode = createNode(data, where->Next);
    ForwardList::Node* prev = where;
    if (prev)
        prev->Next = newNode;
    return newNode;
}
ForwardList::Node* eraseAfter(ForwardList* const list, ForwardList::Node* const node)
{
    ForwardList::Node* node1 = node->Next;
    if ( list->Head == node1 )
    {
        list->Head = list->Head->Next;
        return node1;
    }
    else
    {
        ForwardList::Node *ptr;
        for (ptr = list->Head; ptr->Next != nullptr && ptr->Next != node1; ptr = ptr->Next);
        if (ptr->Next == nullptr)
            return 0;
        else if (ptr->Next == list->Tail)
            list->Tail = ptr;
        ptr->Next = node1->Next;
        delete (node1);
        return ptr;
    }
}
ForwardList::Node* popFront(ForwardList* const list)
{
    ForwardList::Node* next = 0;
    if (list->Head)
    {
        next = list->Head->Next;
        delete list->Head;
        list->Head = next;
    }
    return next;
}
ForwardList::Node* reverse(ForwardList* const list)
{
    ForwardList* list1 = list;
    ForwardList::Node* first = list->Head;
    while (first->Next != nullptr)
    {
        int data = first->Next->Data;
        eraseAfter(list1, first);
        pushFront(list1, data);
    }
    return list->Head;
}
void print(const ForwardList* const ls)
{
    ForwardList::Node* tmp = ls->Head;
    while (tmp)
    {
        std::cout << tmp->Data << std::endl;
        tmp = tmp->Next;
    }
}
