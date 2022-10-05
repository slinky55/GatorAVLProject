#include <iostream>

#include "BST.h"

int main()
{
    BST tree;

    tree.Insert("John Smith", 126498);
    std::cout << tree.Root();

    return 0;
}
