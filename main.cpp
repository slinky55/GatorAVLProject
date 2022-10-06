#include <iostream>

#include "AVL.h"

int main()
{
    AVL tree;

    tree.Insert("John Smith", 126498);
    tree.Insert("Henry Jones", 125000);
    tree.Insert("James Madison", 130000);

    return 0;
}
