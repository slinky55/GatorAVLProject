#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <time.h>

#include "AVL.h"

void ParseFile(AVL& _tree,
               const std::string& _file)
{
    std::ifstream in {_file};
    std::string line;
    std::getline(in, line);

    uint32_t inputs = std::stoi(line);
    uint32_t count {0};

    while (count < inputs)
    {
        std::getline(in, line);
        std::stringstream ss;
        std::string token;
        ss << line;
        ss >> token;

        if (token == "search")
        {
            std::string id;
            ss >> id;
            if (id[0] == '"')
            {
                std::vector<Node*> list;
                id.erase(remove(id.begin(), id.end(), '"'), id.end());
                _tree.Search(id, list);
                if (list.empty())
                    std::cout << "unsuccessful\n";
                else
                    for (auto node : list)
                        std::cout << node->data.first << "\n";
            }
            else
            {
                if (!_tree.Search(std::stoi(id)))
                    std::cout << "unsuccessful\n";
            }
        }

        if (token == "insert")
        {
            std::string _name;
            uint32_t _id;
            ss >> _name >> _id;
            _name.erase(remove(_name.begin(), _name.end(), '"'), _name.end());
            _tree.Insert({_name, _id});
        }

        if (token == "remove")
        {
            int id;
            ss >> id;
            _tree.Remove(id);
        }

        if (token == "printInorder")
        {
            _tree.PrintInOrder();
        }

        if (token == "printPreorder")
        {
            _tree.PrintPreOrder();
        }

        if (token == "printPostorder")
        {
            _tree.PrintPostOrder();
        }

        if (token == "printLevelCount")
        {
            _tree.Height();
        }

        ss.clear();
        token.clear();
        count++;
    }
}

int main()
{
    clock_t tStart = clock();

    AVL testTree;

    ParseFile(testTree, "../Input/5.txt");

    printf("Time taken: %.8fs\n", static_cast<double>(clock() - tStart) / CLOCKS_PER_SEC);

    return 0;
}
