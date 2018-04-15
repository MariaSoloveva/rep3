/*#include <iostream>
#include "set.hpp"


int main()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(5);
    s1.insert(3);
    s1.insert(2);
    s1.insert(8);
    s1.insert(0);
    s1.insert(15);
    s1.insert(20);
    s1.insert(11);
    s1.insert(22);
    s1.insert(19);
    std::cout<< s1.size() <<std::endl;
    std::cout<< s1.empty() <<std::endl;
    s1.find(9);
    std::cout<< s1.has(9) <<std::endl;
    s1.erase(s1.find(19));
    return 0;
}*/

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
    /*x = tree.Find(6);
    tree.Remove(x);
    x = tree.Find(4);
    std::cout << tree.isBST(x) << std::endl;*/
    return 0;
}
