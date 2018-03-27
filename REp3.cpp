#ifndef LAB_03_BST_MARIASOLOVEVA_BST_HPP
#define LAB_03_BST_MARIASOLOVEVA_BST_HPP

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
        Node * where = Root;
        while (where->Left)
            where = where->Left;
        while (where->Right)
            where = where->Right;
        while (where)
        {
            where = where->Parent;
            if (where->Parent->Left)
            {
                delete[] where->Parent->Left;
                where->Parent->Left = NULL;
            }
            if (where->Parent->Right)
            {
                delete[] where->Parent->Right;
                where->Parent->Right = NULL;
            }
            where = where->Parent;
        }
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
    };
private:
    Node* Root;
};


#endif //LAB_03_BST_MARIASOLOVEVA_BST_HPP
