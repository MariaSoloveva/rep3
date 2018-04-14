#include <iostream>
#include "bst.hpp"

int main()
{
    BinarySearchTree<int> tree;
    BinarySearchTree<int>::Node* x;
    tree.Add(4);
    /*tree.Add(5);
    tree.Add(3);
    tree.Add(2);
    tree.Add(6);
    x = tree.Find(5);
    tree.Remove(x);
    x = tree.Find(6);
    tree.Remove(x);
    x = tree.Find(4);*/
    std::cout << tree.isBST(x) << std::endl;
    return 0;
}
