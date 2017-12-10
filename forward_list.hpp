struct ForwardList
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
ForwardList::Node* createNode(const ForwardList::value_type& data, ForwardList::Node* next);
ForwardList* initList();
void destroyList(ForwardList** ls);
ForwardList::Node* pushFront(ForwardList* const list, const ForwardList::value_type & data);
ForwardList::Node* pushBack(ForwardList* const list, const ForwardList::value_type & data);
size_t size(const ForwardList* const list);
ForwardList::Node* insertAfter(ForwardList* const list, ForwardList::Node* const where, const ForwardList::value_type& data);
ForwardList::Node* eraseAfter(ForwardList* const list, ForwardList::Node* const node);
ForwardList::Node* popFront(ForwardList* const list);
ForwardList::Node* reverse(ForwardList* const list);
void print(const ForwardList* const ls);
