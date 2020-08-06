#include <iostream>
#include "standard.h"
#include "set.h"
using std::cin;
using std::cout;
using std::endl;


struct Node
{
    int value;
    int height;
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
    node->height = 1;
    return node;
}


Set* createSet()
{
    Set* set = new Set;
    set->root = nullptr;
    return set;
}

//________

int height(Node* node)
{
    return node ? node->height : 0;
}


int balanceFactor(Node* node)
{
   return height(node->right) - height(node->left);
}


void updateHeight(Node* node)
{
    node->height = max(height(node->left), height(node->right)) + 1;
}


void rotateRight(Node* &root)
{
   Node* pivot = root->left;
   root->left = pivot->right;
   pivot->right = root;
   updateHeight(root);
   updateHeight(pivot);
   root = pivot;
}


void rotateLeft(Node* &root)
{
   Node* pivot = root->right;
   root->right = pivot->left;
   pivot->left = root;
   updateHeight(root);
   updateHeight(pivot);
   root = pivot;
}


void balance(Node* &node)
{
    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->right) < 0)
            rotateRight(node->right);
        rotateLeft(node);
    }
    else if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->left) > 0)
            rotateLeft(node->left);
        rotateRight(node);
    }
    else
        updateHeight(node);
}

//________

void printDebug(Node* node)
{
    if (!node)
        cout << "n";
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
    if (node)
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
    if (node)
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
    if (node)
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
    if (!node)
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
    if (!node)
    {
        node = createNode(value);
        return;
    }
    if (value == node->value)
        return;
    if (value < node->value)
        addElement(value, node->left);
    else
        addElement(value, node->right);    
    balance(node);
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
    if (!node->left && !node->right)
        return noChildren;
    if (!node->right)
        return onlyLeftChild;
    if (!node->left)
        return onlyRightChild;
    return twoChildren;
}


void removeNode(Node* &node);


int copyValueAndDeleteRightmost(Node* &nodeWithRightChild)
{
    int returnValue = 0;
    if (!nodeWithRightChild->right->right)
    {
        returnValue = nodeWithRightChild->right->value;
        removeNode(nodeWithRightChild->right);
    }
    else
        returnValue = copyValueAndDeleteRightmost(nodeWithRightChild->right);
    balance(nodeWithRightChild);
    return returnValue;
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
    {
        if (!node->left->right)
        {
            node->value = node->left->value;
            removeNode(node->left);
        }
        else        
            node->value = copyValueAndDeleteRightmost(node->left);
        balance(node);
        break;
    }
    }
}


void removeElement(int value, Node* &node)
{
    if (!node)
        return;
    if (value == node->value)
    {
        removeNode(node);
        return;
    }
    if (value < node->value)
        removeElement(value, node->left);
    else
        removeElement(value, node->right);
    balance(node);
}


void removeElement(int value, Set* set)
{
    removeElement(value, set->root);
}


bool isEmpty(Set *set)
{
    return !(set->root);
}
