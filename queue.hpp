struct Queue
{
    using value_type = int;

    struct Node
    {
        value_type Data;
        Node* Next;
    };

    Node* Head;
    Node* Tail;
};
void print(const Queue* const ls);
Queue* initQueue();
void destroyQ(Queue** q);
Queue::Node* createNodeForQueue(const Queue::value_type& data, Queue::Node* next);
Queue::Node* push(Queue* const q, const Queue::value_type& data);
void pop(Queue* const q);
Queue::Node* front(Queue* const q);
Queue::Node* back(Queue* const q);
