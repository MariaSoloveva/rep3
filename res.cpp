#include <iostream>

template <class T>
class BinarySearchTree
{
public:
    struct Node
    {
        Node* Parent;
        Node* Left;
        Node* Right;
        T Value;
    };
    BinarySearchTree()
    {
        Root = NULL;
    }
    ~BinarySearchTree()
    {
       delete[] Root;
    }

    Node* createNode(T value, Node *parent)
    {
        Node* tmp = new Node;
        tmp->Left = tmp->Right = NULL;
        tmp->Value = value;
        tmp->Parent = parent;
        return tmp;
    }
    void Add(const T& value)
    {
        Node* root = Root;
        if (Root == NULL)
        {
            Root = createNode(value, Root);
            return;
        }
        else
        {
            Node *where = Root;
            while (where)
            {
                if (value <= Root->Value && where->Left == NULL)
                {
                    where->Left = createNode(value, where);
                    return;
                } else if (value > Root->Value && where->Right == NULL)
                {
                    where->Right = createNode(value, where);
                    return;
                }
                if (value <= where->Value)
                   where = where->Left;
                else
                    where = where->Right;
            }
        }
    }
    Node* Find(const T& value)
    {
        Node * where = Root;
        while (where)
        {
            if (where->Value > value)
            {
                where = where->Left;
                continue;
            }
            else if (where->Value < value)
            {
                where = where->Right;
                continue;
            }
            else
            {
                return where;
            }
        }
        return NULL;
    }
    void Remove(Node* node)
    {
        Node* where = node;
        if (where->Left && where->Right)
        {
            Node* root = where;
            while (root->Right)
            {
                    root = root->Right;
            }
            where->Value = root->Value;
            Remove(root);
            return;
        }
        else if (where->Right)
        {
            if (where == where->Parent->Right)
                where->Parent->Right = where->Right;
            else
                where->Parent->Left = where->Right;
        }
        else if (where->Left)
        {
            if (where == where->Parent->Left)
                where->Parent->Left->Value = where->Value;
            else
                where->Parent->Right->Value = where->Left->Value;
        }
        else
        {
            if (where->Parent->Right == node)
            {
                where->Parent->Right = NULL;
            }
            else
                where->Parent->Left = NULL;
        }
    }
private:
    Node* Root;
};
template <class T>
bool isBST(BinarySearchTree<T>::Node* root)
{
    BinarySearchTree<T>::Node* rootCopy = root;
    if (root == nullptr)
        return true;
    else
    {
        while (root)
        {
            if (root->Right->Value <= root->Value || root->Left->Value > root->Value)
                return false;
            root = root->Left;
            rootCopy = rootCopy->Right;
            return isBST(root) && isBST(rootCopy);
        }
    }
}

int main()
{
    BinarySearchTree<int> tree;
    BinarySearchTree<int>::Node* x;
    tree.Add(4);
    tree.Add(5);
    tree.Add(3);
    tree.Add(2);
    tree.Add(6);
    x = tree.Find(5);
    tree.Remove(x);
    x = tree.Find(6);
    tree.Remove(x);
    return 0;
}
