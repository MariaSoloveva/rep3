struct Stack
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
Stack* initStack();
void destroyS(Stack** st);
Stack::Node* createNodeForStack(const Stack::value_type& data, Stack::Node* next);
Stack::Node* push(Stack* const st, const Stack::value_type& data);
void pop(Stack* const st);
Stack::Node* top(Stack* const st);
