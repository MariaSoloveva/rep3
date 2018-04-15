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

    Node* createNode(T value, Node *parent)
    {
        Node* tmp = new Node;
        tmp->Right = tmp->Left = NULL;
        tmp->Value = value;
        tmp->Parent = parent;
        return tmp;
    }
    void Add(const T& value)
    {
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
                where = where->Left;
            else if (where->Value < value)
                where = where->Right;
            else
                return where;
        }
        return NULL;
    }
    void Remove(Node* node)
    {
        if (node->Left && node->Right) {
            Node* root = node;
            while (root->Right)
            {
                root = root->Right;
            }
            node->Value = root->Value;
            Remove(root);
            return;
        } else if (node->Left) {
            if (node == node->Parent->Left) {
                node->Parent->Left = node->Left;
            } else {
                node->Parent->Right = node->Left;
            }
        } else if (node->Right) {
            if (node == node->Parent->Right) {
                node->Parent->Right = node->Right;
            } else {
                node->Parent->Left = node->Right;
            }
        } else {
            if (node == node->Parent->Left) {
                node->Parent->Left = NULL;
            } else {
                node->Parent->Right = NULL;
            }
        }
        free(node);
    }
    bool isBST(BinarySearchTree<T>::Node* rootOfTree)
    {
        BinarySearchTree<T>::Node* rootCopy = rootOfTree;
        if (rootOfTree == nullptr)
            return true;
        else
        {
            while (rootOfTree)
            {
                if (rootOfTree->Right)
                    if (rootOfTree->Right->Value <= rootOfTree->Value)
                        return false;
                if (rootOfTree->Left)
                    if (rootOfTree->Left->Value > rootOfTree->Value)
                        return false;
                rootOfTree = rootOfTree->Left;
                rootCopy = rootCopy->Right;
                return isBST(rootOfTree) && isBST(rootCopy);
            }
        }
        return true;
    }
 private:
        Node* Root;
};
