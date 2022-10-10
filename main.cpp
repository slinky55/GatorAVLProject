#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "AVL.h"

bool IsValidName(const std::string& _name)
{
    for (auto& c : _name)
    {
        if (c == ' ') continue;
        if (!std::isalpha(c)) return false;
    }
    return true;
}

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

        if (token == "removeInorder")
        {
            int n;
            ss >> n;
            _tree.RemoveInOrder(n);
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

void ParseInput(AVL& _tree)
{
    std::string line;
    std::getline(std::cin, line);

    uint32_t inputs = std::stoi(line);
    uint32_t count {0};

    while (count < inputs)
    {
        std::getline(std::cin, line);
        std::stringstream ss;
        std::string command;
        ss << line;
        ss >> command;

        if (command == "search")
        {
            std::string id;
            ss >> id;
            if (id[0] == '"')
            {
                std::vector<Node*> list;
                id.erase(remove(id.begin(), id.end(), '"'), id.end());
                if (!IsValidName(id))
                {
                    std::cout << "unsuccessful\n";
                }
                else
                {
                    _tree.Search(id, list);
                    if (list.empty())
                        std::cout << "unsuccessful\n";
                    else
                        for (auto node : list)
                            std::cout << node->data.first << "\n";
                }
            }
            else
            {
                if (!_tree.Search(std::stoi(id)))
                    std::cout << "unsuccessful\n";
            }
        }

        if (command == "insert")
        {
            std::string _name;
            uint32_t _id;
            ss >> _name >> _id;
            _name.erase(remove(_name.begin(), _name.end(), '"'), _name.end());

            if (!IsValidName(_name))
            {
                std::cout << "unsuccessful\n";
            }
            else
            {
                _tree.Insert({_name, _id});
            }
        }

        if (command == "remove")
        {
            int id;
            ss >> id;
            _tree.Remove(id);
        }

        if (command == "removeInorder")
        {
            int n;
            ss >> n;
            _tree.RemoveInOrder(n);
        }

        if (command == "printInorder")
        {
            _tree.PrintInOrder();
        }

        if (command == "printPreorder")
        {
            _tree.PrintPreOrder();
        }

        if (command == "printPostorder")
        {
            _tree.PrintPostOrder();
        }

        if (command == "printLevelCount")
        {
            _tree.Height();
        }
        count++;
    }
}

int main()
{
    AVL testTree;
    ParseInput(testTree);
    return 0;
}
