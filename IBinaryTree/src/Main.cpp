#include <iostream>
#include "BinaryTree.h"

int main()
{
    BinaryTree<float> tree;
    tree.Insert(5);
    tree.Insert(2);
    tree.Insert(7);
    tree.Insert(1);
    tree.Insert(3);
    tree.Insert(6);
    tree.Insert(8);
    tree.Insert(4);
    tree.Insert(9);
    tree.Insert(10);

    std::cout << std::endl << "Before removing 5:" << std::endl;
    tree.Display();

    if (tree.Remove(5)) {
        std::cout << std::endl << "5 was successfully removed." << std::endl;
    }
    else {
        std::cout << "5 was not found in the tree." << std::endl;
    }

    std::cout << "After removing 5:" << std::endl;
    tree.Display();

    return 0;
}