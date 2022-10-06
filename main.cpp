#include <iostream>
#include <cassert>

#include "AVL.h"

void PrintNode(Node*& node)
{
    assert(node);
    std::cout << node->data.first << " | " << node->data.second << "\n";
}

int main()
{
    clock_t tStart = clock();

    AVL tree;

    tree.Insert("John Smith", 126498);
    tree.Insert("Henry Jones", 125000);
    tree.Insert("James Madison", 130000);

    Node* madison = tree.Search(130000);
    PrintNode(madison);

    Node* smith = tree.Search("John Smith");
    PrintNode(smith);

    printf("Time taken: %.8fs\n", static_cast<double>(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
