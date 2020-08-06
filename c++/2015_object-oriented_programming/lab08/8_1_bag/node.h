#pragma once
#include <iostream>
#include <algorithm>
#include "bag.h"

template <typename T>
class Bag;

/// Node of the Bag class tree
template <typename T>
class Node
{
private:
    friend class Bag<T>;
    enum childrenAmount
    {
        noChildren,
        onlyLeftChild,
        onlyRightChild,
        twoChildren
    };
    Node(T value) : value(value), height_(1), amount(1), left(nullptr), right(nullptr) {}
    static int height(Node *node) { return node ? node->height_ : 0; }
    int balanceFactor() const { return height(right) - height(left); }
    void updateHeight() { height_ = std::max(height(left), height(right)) + 1; }
    static void rotateLeft(Node *&root);
    static void rotateRight(Node *&root);
    static void balance(Node *&node);
    static void printAscending(Node *node, std::ostream &output);
    static void printDebugToConsole(Node *node);
    static bool elementExists(const T &value, Node *node);
    static void addElement(const T &value, Node *&node);
    int childrenAmount() const;
    static Node *createCopyOfRightmostAndRemoveIt(Node *&nodeWithRightChild);
    static void removeElement(const T &value, Node *&node);
    static void removeNode(Node *&node);
    static void deleteNodeAndItsChildren(Node *node);
    T value;
    int height_;
    int amount;
    Node* left;
    Node* right;
};

template <typename T>
void Node<T>::deleteNodeAndItsChildren(Node *node)
{
    if (node)
    {
        deleteNodeAndItsChildren(node->left);
        deleteNodeAndItsChildren(node->right);
        delete node;
    }
}

template <typename T>
void Node<T>::rotateLeft(Node* &root)
{
   Node* pivot = root->right;
   root->right = pivot->left;
   pivot->left = root;
   root->updateHeight();
   pivot->updateHeight();
   root = pivot;
}

template <typename T>
void Node<T>::rotateRight(Node* &root)
{
   Node* pivot = root->left;
   root->left = pivot->right;
   pivot->right = root;
   root->updateHeight();
   pivot->updateHeight();
   root = pivot;
}

template <typename T>
void Node<T>::balance(Node* &node)
{
    if (node->balanceFactor() == 2)
    {
        if (node->right->balanceFactor() < 0)
            rotateRight(node->right);
        rotateLeft(node);
    }
    else if (node->balanceFactor() == -2)
    {
        if (node->left->balanceFactor() > 0)
            rotateLeft(node->left);
        rotateRight(node);
    }
    else
        node->updateHeight();
}

template <typename T>
void Node<T>::printAscending(Node* node, std::ostream &output)
{
    if (node)
    {
        printAscending(node->left, output);
        for (int i = 0; i < node->amount; i++)
            output << node->value << ' ';
        printAscending(node->right, output);
    }
}

template <typename T>
void Node<T>::printDebugToConsole(Node* node)
{
    using std::cout;
    if (!node)
        cout << "n";
    else
    {
        cout << '(' << node->value << ' ';
        printDebugToConsole(node->left);
        cout << ' ';
        printDebugToConsole(node->right);
        cout << ')';
    }
}

template <typename T>
bool Node<T>::elementExists(const T &value, Node* node)
{
    if (!node)
        return false;
    if (value < node->value)
        return elementExists(value, node->left);
    if (value > node->value)
        return elementExists(value, node->right);
    return true;
}

template <typename T>
void Node<T>::addElement(const T &value, Node* &node)
{
    if (!node)
        node = new Node(value);
    else
    {
        if (value == node->value)
            node->amount += 1;
        else
        {
            if (value < node->value)
                addElement(value, node->left);
            else
                addElement(value, node->right);
            balance(node);
        }
    }
}

template <typename T>
int Node<T>::childrenAmount() const
{
    if (!left && !right)
        return noChildren;
    if (!right)
        return onlyLeftChild;
    if (!left)
        return onlyRightChild;
    return twoChildren;
}

template <typename T>
void Node<T>::removeElement(const T &value, Node* &node)
{
    if (node)
    {
        if (value == node->value)
        {
            if (node->amount == 1)
                removeNode(node);
            else
                node->amount -= 1;
        }
        else
        {
            if (value < node->value)
                removeElement(value, node->left);
            else
                removeElement(value, node->right);
            balance(node);
        }
    }
}

template <typename T>
Node<T>* Node<T>::createCopyOfRightmostAndRemoveIt(Node* &nodeWithRightChild)
{
    Node* copyOfRightmost = nullptr;
    if (!nodeWithRightChild->right->right)
    {
        copyOfRightmost = new Node(nodeWithRightChild->right->value);
        copyOfRightmost->amount = nodeWithRightChild->right->amount;
        removeNode(nodeWithRightChild->right);
    }
    else
        copyOfRightmost = createCopyOfRightmostAndRemoveIt(nodeWithRightChild->right);
    balance(nodeWithRightChild);
    return copyOfRightmost;
}

template <typename T>
void Node<T>::removeNode(Node* &node)
{
    switch (node->childrenAmount())
    {
    case noChildren:
    {
        delete node;
        node = nullptr;
        break;
    }
    case onlyLeftChild:
    {
        Node* nodeToDelete = node;
        node = node->left;
        delete nodeToDelete;
        break;
    }
    case onlyRightChild:
    {
        Node* nodeToDelete = node;
        node = node->right;
        delete nodeToDelete;
        break;
    }
    case twoChildren:
    {
        if (!node->left->right)
        {
            node->value = node->left->value;
            node->amount = node->left->amount;
            removeNode(node->left);
        }
        else
        {
            Node* auxiliary = createCopyOfRightmostAndRemoveIt(node->left);
            node->value = auxiliary->value;
            node->amount = auxiliary->amount;
            delete auxiliary;
        }
        balance(node);
        break;
    }
    }
}
