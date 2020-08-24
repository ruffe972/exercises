#include <iostream>
#include "set.h"
using namespace std;


struct Node
{
    int value;
    Node* left;
    Node* right;
};


struct Set
{
    Node* root;
};


Node* createNode(int value)
{
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}


Set* createSet()
{
    Set* set = new Set;
    set->root = nullptr;
    return set;
}

//________

void printDebug(Node* node)
{
    if (node == nullptr)
        cout << "null";
    else
    {
        cout << '(' << node->value << ' ';
        printDebug(node->left);
        cout << ' ';
        printDebug(node->right);
        cout << ')';
    }
}


void printDebug(Set* set)
{
    printDebug(set->root);
}

//________

void printAscending(Node* node)
{
    if (node != nullptr)
    {
        printAscending(node->left);
        cout << node->value << ' ';
        printAscending(node->right);
    }
}


void printAscending(Set* set)
{
    printAscending(set->root);
}

//________

void printDescending(Node* node)
{
    if (node != nullptr)
    {
        printDescending(node->right);
        cout << node->value << ' ';
        printDescending(node->left);
    }
}


void printDescending(Set* set)
{
    printDescending(set->root);
}

//________

void deleteSet(Node* node)
{
    if (node != nullptr)
    {
        deleteSet(node->left);
        deleteSet(node->right);
        delete node;
    }
}


void deleteSet(Set* set)
{
    deleteSet(set->root);
    delete set;
}

//________

bool elementExists(int value, Node* node)
{
    if (node == nullptr)
        return false;
    if (value < node->value)
        return elementExists(value, node->left);
    if (value > node->value)
        return elementExists(value, node->right);
    return true;
}


bool elementExists(int value, Set* set)
{
    return elementExists(value, set->root);
}

//________

void addElement(int value, Node* &node)
{
    if (node == nullptr)
        node = createNode(value);
    else if (value < node->value)
        addElement(value, node->left);
    else if (value > node->value)
        addElement(value, node->right);
}


void addElement(int value, Set* set)
{
    addElement(value, set->root);
}

//________

enum childrenAmount
{
    noChildren,
    onlyLeftChild,
    onlyRightChild,
    twoChildren
};


int childrenAmount(Node* node)
{
    if (node->left == nullptr && node->right == nullptr)
        return noChildren;
    if (node->right == nullptr)
        return onlyLeftChild;
    if (node->left == nullptr)
        return onlyRightChild;
    return twoChildren;
}


Node* preRightmost(Node* nodeWithRightChild)
{
    if (nodeWithRightChild->right->right == nullptr)
        return nodeWithRightChild;
    return preRightmost(nodeWithRightChild->right);
}


void removeNode(Node* &node)
{
    switch (childrenAmount(node))
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
        if (node->left->right == nullptr)
        {
            node->value = node->left->value;
            removeNode(node->left);
        }
        else
        {
            Node* preRightmostNode = preRightmost(node->left);
            node->value = preRightmostNode->right->value;
            removeNode(preRightmostNode->right);
        }
        break;
    }
}


void removeElement(int value, Node* &node)
{
    if (node != nullptr)
    {
        if (value < node->value)
            removeElement(value, node->left);
        else if (value > node->value)
            removeElement(value, node->right);
        else
            removeNode(node);
    }
}


void removeElement(int value, Set* set)
{
    removeElement(value, set->root);
}
