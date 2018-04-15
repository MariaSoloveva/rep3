#include <iostream>
#include <exception>

template <class T>
class set
{
    struct Node
    {
        Node* Parent;
        Node* Left;
        Node* Right;
        T Value;
    };
    Node* Root;
    Node* createNode(T value, Node *parent)
    {
        Node* tmp = new Node;
        tmp->Right = tmp->Left = NULL;
        tmp->Value = value;
        tmp->Parent = parent;
        return tmp;
    }
    void copy(Node* node, Node* nodeS)
    {
        node = new Node;
        node = nodeS;
        if (!node->Right && !node->Left)
            return;
        if (nodeS->Parent != NULL)
        {
            if (nodeS->Left)
                copy(node->Left, nodeS->Left);
            if (nodeS->Right)
                copy(node->Right, nodeS->Right);
        }
    }
public:
    class Iterator
            : public std::iterator<std::random_access_iterator_tag, T>
    {
    private:
        Node *ptr;
    public:
        explicit Iterator(Node *n)
                : ptr(n)
        {}
        Node &operator*()
        {
            return *ptr;
        }
        Node *operator->()
        {
            return ptr;
        }
        Iterator &operator++()
        {
            if (ptr->Parent == NULL)
            {
                ptr = ptr->Right;
                while (ptr->Left)
                    ptr = ptr->Left;
                return *this;
            }
            if (ptr == ptr->Parent->Left)
            {
                if (!ptr->Right)
                    ptr = ptr->Parent;
                else
                {
                    ptr = ptr->Right;
                    while (ptr->Left)
                        ptr = ptr->Left;
                }
            }
            else
            {
                if (ptr->Right)
                {
                    ptr = ptr->Right;
                    if (ptr->Left)
                        while (ptr->Left)
                            ptr = ptr->Left;
                }
                else
                {
                    T val = ptr->Value;
                    while (val > ptr->Parent->Value)
                        ptr = ptr->Parent;
                    ptr = ptr->Parent;
                }
            }
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator it(ptr);
            ++ptr;
            return it;
        }
        Iterator &operator+=(size_t n)
        {
            for (size_t i = 0; i < n; ++i)
                ++ptr;
            return *this;
        }
        Iterator &operator-=(size_t n)
        {
            for (size_t i = 0; i < n; ++i)
                --ptr;
            return *this;
        }
        Iterator &operator--()
        {
            if (ptr->Parent == NULL)
            {
                ptr = ptr->Left;
                while (ptr->Right)
                    ptr = ptr->Right;
                return *this;
            }
            if (ptr->Parent->Right == ptr)
            {
                if (ptr->Left->Right)
                {
                    ptr = ptr->Left->Right;
                    while (ptr->Right)
                        ptr = ptr->Right;
                }
                else
                    ptr = ptr->Parent;
            }
            else
            {
                if (ptr->Left)
                {
                    ptr = ptr->Left;
                    while (ptr->Right)
                        ptr = ptr->Right;
                }
                else
                {
                    T val = ptr->Value;
                    while (val < ptr->Parent->Value)
                        ptr = ptr->Parent;
                    ptr = ptr->Parent;
                }
            }
            return *this;
        }
        Iterator operator--(int)
        {
            Iterator it(ptr);
            --ptr;
            return it;
        }
        bool operator==(Iterator it)
        {
            return ptr == it.ptr;
        }
        bool operator<(Iterator it)
        {
            return ptr < it.ptr;
        }
        bool operator<=(Iterator it)
        {
            return this->operator==(it) || this->operator<(it);
        }
        bool operator>(Iterator it)
        {
            return !(this->operator==(it) || this->operator<(it));
        }
        bool operator>=(Iterator it)
        {
            return !this->operator<(it);
        }
        bool operator!=(Iterator it)
        {
            return !(this->operator==(it));
        }
    };
    using value_type = T;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = T*;
    using const_pointer = const T*;
    using iterator = Iterator;
    using const_iterator = const Iterator;
    set()
    {
        Root = NULL;
    }
    ~set()
    {
        if (Root != NULL)
        {
            Node *where = Root;
            while (where->Left)
                where = where->Left;
            while (where->Right)
                where = where->Right;
            while (Root->Right || Root->Left)
            {
                where = where->Parent;
                if (where->Parent == NULL && where->Left != NULL)
                {
                    delete where->Left;
                    where->Left = NULL;
                    while (where->Right)
                        where = where->Right;
                    while (where->Left)
                        where = where->Left;
                }
                if (where->Left)
                {
                    delete where->Left;
                    where->Left = NULL;
                }
                if (where->Right)
                {
                    delete where->Right;
                    where->Right = NULL;
                }
            }
            delete Root;
            Root = NULL;
        }
    }
    set(const set& s)
    {
        Root = s.Root;
        if (s.Root->Left)
            copy(Root->Left, s.Root->Left);
        if (s.Root->Right)
            copy(Root->Right, s.Root->Right);
    }
    set& operator=(const set& s)
    {
        if (s.Root != NULL)
        {
            set::~set();
            Root = new Node;
            Root = s.Root;
            if (s.Root->Left)
                copy(Root->Left, s.Root->Left);
            if (s.Root->Right)
                copy(Root->Right, s.Root->Left);
        }
    }
    iterator begin()
    {
        Node* where = Root;
        while(where->Left)
            where = where->Left;
        return iterator(where);
    }
    const_iterator begin() const
    {
        Node* where = Root;
        while(where->Left)
            where = where->Left;
        return const_iterator(where);
    }
    iterator end()
    {
        Node* where = Root;
        while(where->Right)
            where = where->Right;
        return iterator(where);
    }
    const_iterator end() const
    {
        Node* where = Root;
        while(where->Right)
            where = where->Right;
        return const_iterator(where);
    }
    size_type size() const
    {
        size_type treeSize = 0;
        if (Root != NULL)
        {
            treeSize = 1;
            for (iterator i = begin(); i != end(); ++i)
                ++treeSize;
        }
        return treeSize;
    }
    bool empty() const
    {
        return size() == 0;
    }
    bool has(const value_type& value)
    {
        if (Root != NULL)
        {
            for (iterator i = begin(); i != end(); ++i)
            {
                if (i->Value == value)
                    return 1;
            }
        }
        return 0;
    }
    iterator insert(const value_type& value)
    {
        if (Root == NULL)
        {
            Root = createNode(value, Root);
            return iterator(Root);
        }
        else
        {
            if (has(value))
                return iterator(Root);
            Node *where = Root;
            while (where)
            {
                if (value <= where->Value && where->Left == NULL)
                {
                    where->Left = createNode(value, where);
                    return iterator(where);
                } else if (value > where->Value && where->Right == NULL)
                {
                    where->Right = createNode(value, where);
                    return iterator(where);
                }
                if (value <= where->Value)
                    where = where->Left;
                else
                    where = where->Right;
            }
            return iterator(where);
        }
    }
    void erase(iterator  node)
    {
        Node where1 = *node;
        Node* where = &where1;
        if (node->Left && node->Right) {
            while (where->Right)
            {
                where = where->Right;
            }
            node->Value = where->Value;
            erase(iterator(where));
            return;
        } else if (where->Left) {
            if (where == node->Parent->Left) {
                node->Parent->Left = node->Left;
            } else {
                node->Parent->Right = node->Left;
            }
        } else if (where->Right) {
            if (where == node->Parent->Right) {
                node->Parent->Right = node->Right;
            } else {
                node->Parent->Left = node->Right;
            }
        } else {
            Node* root = &(*node);
            if (where == node->Parent->Left) {
                delete root;
                node->Parent->Left = NULL;
            } else {
                delete root;
                node->Parent->Right = NULL;
            }
        }
    }
    void swap(set& other)
    {
        Node* tmp;
        tmp = other.Root;
        other.Root = Root;
        Root = tmp;
    }
    void clear()
    {
        if (Root != NULL)
        {
            for (iterator i = begin(); i != end(); ++i)
            {
                i->Value = 0;
            }
        }
        return;
    }
    iterator find(const T& value)
    {
        if (Root != NULL)
        {
            for (iterator i = begin(); i != end(); ++i)
            {
                if (i->Value == value)
                    return i;
            }
        }
        throw std::invalid_argument("There is value like this");
    }
    const_iterator find(const T& value) const
    {
        if (Root != NULL)
        {
            for (iterator i = begin(); i != end(); ++i)
            {
                if (i->Value == value)
                    return i;
            }
        }
        throw std::invalid_argument("There is value like this");
    }
    bool operator==(const set<T>& b)
    {
        for (iterator i = begin(), j = b.begin(); i != end(); ++i)
        {
            if (size() == b.size())
                if ( i != j)
                    return false;
            return false;
        }
        return true;
    }
};

template<class T>
bool operator!=(const set<T>& a, const set<T>& b)
{
    return !(a == b);
}

