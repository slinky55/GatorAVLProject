#pragma once

#include <cstdint>
#include <string>
#include <utility>

using DataPair = std::pair<std::string, uint32_t>;

struct Node
{
    Node* left {nullptr};
    Node* right {nullptr};

    DataPair data;
};

class BST
{
public:
    BST() = default;

    const Node* Insert(std::string_view _name,
                       uint32_t _id);

    const Node* Search(uint32_t _id);
    const Node* Search(std::string_view _name);

    uint32_t Root()
    {
        return root->data.second;
    }
private:
    Node* root {nullptr};

    const Node* Insert(Node* _node,
                       std::string_view _name,
                       uint32_t _id);
};
