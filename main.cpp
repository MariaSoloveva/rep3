#include <iostream>
#include"bst.hpp"

int main()
{
    BinarySearchTree<int> tree;
    BinarySearchTree<int>::Node* x;
    tree.Add(20);
    tree.Add(15);
    tree.Add(10);
    tree.Add(11);
    tree.Add(16);
    tree.Add(25);
    tree.Add(30);
    tree.Add(24);
    tree.Add(35);
    tree.Add(31);
    x = tree.Find(11);
    tree.Remove(x);
    /*  x = tree.Find(6);
    tree.Remove(x);
    x = tree.Find(4);
    std::cout << tree.isBST(x) << std::endl;*/
    return 0;
}
