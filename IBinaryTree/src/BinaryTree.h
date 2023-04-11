#pragma once
#include "Node.h"
#include <iostream>
#include <vector>
#include <map>


// DecisionTree class for implementing a binary search tree for typename T
template <typename T>
class BinaryTree
{
private:
    Node<T>* root; // root of the binary search tree
    int size;

    void realDisplay(bool draw, std::map<int, std::vector<T>>& m)
    {
        if (draw)
        {
            for (auto& p : m)
            {
                for (auto& v : p.second)
                {
                    std::cout << v << " ";
                }
                p.second.clear();
                std::cout << std::endl;
            }
            m.clear();
        }
    }

    void removeNode(Node<T>* n, Node<T>* parent)
    {
        // Remove the Node<T>
        if (n->hasLeftChild() && !n->hasRightChild())
        {
            // The Node<T> has no left child, replace it with the right child
            if (parent == nullptr)   root = n->getLeftChild();
            else if (parent->getLeftChild() == n) parent->setLeftChild(n->getLeftChild());
            else    parent->setRightChild(n->getLeftChild());

            n->setLeftChild(nullptr);
            delete n;
        }
        else if (n->hasRightChild() && !n->hasLeftChild())
        {
            // The Node<T> has no right child, replace it with the left child
            if (parent == nullptr)   root = n->getRightChild();
            else if (parent->getLeftChild() == n) parent->setLeftChild(n->getRightChild());
            else    parent->setRightChild(n->getRightChild());

            n->setRightChild(nullptr);
            delete n;
        }
        else if (n->hasRightChild() && n->hasLeftChild())
        {
            // The Node<T> has two children, replace it with its successor
            Node<T>* successor = n->getRightChild();
            Node<T>* subparent = nullptr;

            while (successor->hasLeftChild())
            {
                subparent = successor;
                successor = successor->getLeftChild();
            }
            if (subparent != nullptr)
            {
                subparent->setLeftChild(successor->getRightChild());
                successor->setRightChild(n->getRightChild());
            }

            successor->setLeftChild(n->getLeftChild());


            if (parent == nullptr)   root = successor;
            else if (parent->getLeftChild() == n) parent->setLeftChild(successor);
            else parent->setRightChild(successor);

            if (subparent != nullptr)
            {
                std::cout << "\n\n" << successor->getValue() << " " << subparent->getValue() << " " << subparent->hasLeftChild()<< "\n\n";
                if (successor == subparent->getLeftChild())  
                    subparent->setLeftChild(nullptr);
                else 
                    subparent->setRightChild(nullptr);
            }

            n->setLeftChild(nullptr);
            n->setRightChild(nullptr);
            delete n;
        }
        else
        {
            if (parent != nullptr)
            {
                if (parent->getLeftChild() == n) parent->setLeftChild(nullptr);
                else parent->setRightChild(nullptr);
            }
            delete n;
        }
    }
public:

    int getsize()
    {
        return size;
    }

    // Insert a new value into the binary search tree
    void Insert(T value)
    {
        Node<T>* n;
        n = root;
        while (n->isValueSet())
        {
            if (n->getValue() < value)
                n = n->getLeftChild();
            else
                n = n->getRightChild();
        }
        n->setValue(value);
        size++;
    }


    // Search for a Node<T> with a given value in the binary search tree
    // Return a pointer to the Node<T> if found, nullptr otherwise
    Node<T>* Search(T value, Node<T>*& parent = nullptr) const
    {
        parent = nullptr;
        Node<T>* n = root;
        while (n->isValueSet())
        {
            if (n->getValue() == value)
                return n;
            parent = n;
            if (n->getValue() < value)
                n = n->getLeftChild();
            else
                n = n->getRightChild();
        }
        return nullptr;
    }

    // Remove a Node<T> with a given value from the binary search tree
    // Return true if the Node<T> was successfully removed, false otherwise
    bool Remove(T value)
    {
        Node<T>* parent = nullptr;
        Node<T>* n = Search(value,parent);

        // The Node<T> to remove was not found
        if (n == nullptr)
            return false;

        removeNode(n, parent);
        size--;
        return true;
    }


    void Display(Node<T>* dn = nullptr, int Lvl = 0)
    {
        static std::map<int, std::vector<T>> m;
        if (dn == nullptr)
            dn = root;

        m[Lvl].push_back(dn->getValue());

        if (dn->hasLeftChild())
            Display(dn->getLeftChild(), Lvl + 1);

        if (dn->hasRightChild())
            Display(dn->getRightChild(), Lvl + 1);
        
        realDisplay(dn == root, m);
    }


    BinaryTree() : root(new Node<T>()), size(0) {}
    ~BinaryTree()
    {
        delete root;
    }
};