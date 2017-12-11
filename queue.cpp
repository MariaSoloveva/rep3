#include<algorithm>
#include <iostream>
#include"queue.hpp"

void print(const Queue* const ls)
{
    Queue::Node* tmp = ls->Head;
    while (tmp)
    {
        std::cout << tmp->Data << std::endl;
        tmp = tmp->Next;
    }
}
Queue* initQueue()
{
    Queue* q = new Queue();
    q->Head = nullptr;
    return q;
}
void destroyQ(Queue** q)
{
    Queue* queue = *q;
    Queue::Node* tail = queue->Tail;
    while (tail)
    {
        Queue::Node* tmp = tail->Next;
        delete tail;
        tail = tmp;
    }
    delete queue;
    *q = nullptr;
}
Queue::Node* createNodeForQueue(const Queue::value_type& data, Queue::Node* next)
{
    Queue::Node* node = new Queue::Node();
    node->Data = data;
    node->Next = next;
    return node;
}
Queue::Node* push(Queue* const q, const Queue::value_type& data)
{
    Queue::Node* node = createNodeForQueue(data, nullptr);
    if (q->Tail)
        q->Tail->Next = node;
    q->Tail = node;
    if (q->Head == nullptr)
        q->Head = node;
    return node;
}
void pop(Queue* const q)
{
    Queue::Node* next = 0;
    if (q->Head)
    {
        next = q->Head->Next;
        delete q->Head;
        q->Head = next;
    }
}
Queue::Node* front(Queue* const q)
{
    return q->Head;
}
Queue::Node* back(Queue* const q)
{
    return q->Tail;
}
