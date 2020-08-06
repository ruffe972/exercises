#pragma once
#include <iostream>
#include "node.h"

/// Bag (multiset) based on an AVL-tree
template <typename T>
class Bag
{
public:
    Bag() : root(nullptr) {}
    ~Bag() { clear(); }
    /// Print all the elements of a bag in the ascending order
    void printAscending(std::ostream &output) const { Node<T>::printAscending(root, output); }
    /// Output format: (node left_tree right_tree). Doesn't print duplicates
    void printDebugToConsole() const;
    /// Check if the element exists in a bag
    bool exists(const T &value) const { return Node<T>::elementExists(value, root); }
    /// Add an element to the bag
    void add(const T &value) { Node<T>::addElement(value, root); }
    /// Check if the bag is empty
    bool empty() const { return !root; }
    /// Remove an element from the bag
    void remove(const T &value) { Node<T>::removeElement(value, root); }
    /// Delete all contents of the bag
    void clear();
private:
    Node<T>* root;
};

template <typename T>
void Bag<T>::printDebugToConsole() const
{
    Node<T>::printDebug(root);
    std::cout << '\n';
}

template <typename T>
void Bag<T>::Bag::clear()
{
    if (root)
    {
        Node<T>::deleteNodeAndItsChildren(root);
        root = nullptr;
    }
}
