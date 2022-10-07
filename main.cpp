#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "AVL.h"

void PrintNode(Node*& node)
{
    if (!node) { std::cout << "Node not found\n"; return; }
    std::cout << node->data.first << " | " << node->data.second << "\n";
}

void ParseFile(AVL& _tree,
               const std::string& _file)
{
    std::ifstream in {_file};
    std::string line;

    std::getline(in, line);
    //int inputs = std::stoi(line);

    while (std::getline(in, line))
    {
        std::stringstream ss {line};
        std::string token;
        ss >> token;

        if (token == "search")
        {
            std::string _id;
            ss >> _id;
            if (_id[0] == '"')
            {
                std::cout << "Searching for " << _id << "\n";
                _id.erase(remove(_id.begin(), _id.end(), '"'), _id.end());
                if(_tree.Search(_id)) std::cout << "successful\n";
                else std::cout << "unsuccessful\n";
            }
            else
            {
                std::cout << "Searching for " << _id << "\n";
                if(_tree.Search(std::stoi(_id))) std::cout << "successful\n";
                else std::cout << "unsuccessful\n";
            }
        }

        if (token == "insert")
        {
            // "Adam" 12345678
            std::string _name;
            uint32_t _id;

            ss >> _name >> _id;
            _name.erase(remove(_name.begin(), _name.end(), '"'), _name.end());

            std::cout << "Inserting: " << _name << " | " << _id << "\n";
            if (_tree.Insert(_name, _id)) std::cout << "successful\n";
            else std::cout << "unsuccessful\n";
        }
        std::cout << "\n";
    }
}

int main()
{
    clock_t tStart = clock();

    AVL tree;

    /*tree.Insert("John Smith", 50);
    tree.Insert("Henry Jones", 40);
    tree.Insert("James Madison", 75);
    tree.Insert("Bryant Mason", 10);

    Node* madison = tree.Search(75);
    PrintNode(madison);

    Node* smith = tree.Search("Henry Jones");
    PrintNode(smith);

    Node* me = tree.Search(10);
    PrintNode(me);

    tree.Delete(10);
    Node* deleted = tree.Search(10);
    PrintNode(deleted);*/

    ParseFile(tree, "../Input/2.txt");

    printf("Time taken: %.8fs\n", static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC);

    return 0;
}
