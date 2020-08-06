#include <iostream>
#include <fstream>
#include "calculatingTree.h"
using std::endl;


int main()
{
    std::ifstream inputFile;
    inputFile.open("tree.txt");
    Tree* tree = createTree();
    buildTreeFromFile(inputFile, tree);
    printTree(tree);
    std::cout << " = " << calculateAndDelete(tree) << endl;
    inputFile.close();
    return 0;
}
