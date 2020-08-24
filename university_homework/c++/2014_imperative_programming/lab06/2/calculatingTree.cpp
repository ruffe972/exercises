#include <iostream>
#include "calculatingTree.h"
using std::cout;


struct Element
{
    int value;
    Element* left;
    Element* right;
};


struct Tree
{
    Element* root;
};


Element* createElement(int value)
{
    Element* element = new Element;
    element->value = value;
    element->left = nullptr;
    element->right = nullptr;
    return element;
}


Tree* createTree()
{
    Tree* tree = new Tree;
    tree->root = nullptr;
    return tree;
}


bool noChildren(Element* element)
{
    //It is impossible for a node to have the only one child in this kind of a tree.
    return element->left == nullptr;
}


void buildTreeFromFile(std::istream &file, Element* &element)
{
    element = createElement(0);
    if (file.get() == '(')
    {
        //operation
        element->value = file.get();
        //' '
        file.get();
        //first operand
        buildTreeFromFile(file, element->left);
        //' '
        file.get();
        //second operand
        buildTreeFromFile(file, element->right);
        //')'
        file.get();
    }
    else
    {
        file.unget();
        file >> element->value;
    }
}


void buildTreeFromFile(std::istream &file, Tree* tree)
{
    buildTreeFromFile(file, tree->root);
}


void printTree(Element* element)
{
    if (noChildren(element))
        cout << element->value;
    else
    {
        cout << '(';
        printTree(element->left);
        cout << ' ' << (char)(element->value) << ' ';
        printTree(element->right);
        cout << ')';
    }
}


void printTree(Tree* tree)
{
    printTree(tree->root);
}


double performOperation(double firstNumber, char operation, double secondNumber)
{
    switch (operation)
    {
    case '+':
        return firstNumber + secondNumber;
    case '-':
        return firstNumber - secondNumber;
    case '*':
        return firstNumber * secondNumber;
    case '/':
        return firstNumber / secondNumber;
    default:
        return 0;
    }
}


double calculateAndDelete(Element* element)
{
    double returnValue = element->value;
    if (!noChildren(element))
    {
        double leftOperand = calculateAndDelete(element->left);
        double rightOperand = calculateAndDelete(element->right);
        returnValue = performOperation(leftOperand, element->value, rightOperand);
    }
    delete element;
    return returnValue;
}


double calculateAndDelete(Tree* tree)
{
    double returnValue = calculateAndDelete(tree->root);
    delete tree;
    return returnValue;
}
