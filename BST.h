#pragma once

#include <cstdint>
#include <string>
#include <string_view>
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

    const Node* Insert(const std::string& _name,
                       uint32_t _id);

    const Node* Search(uint32_t _id);
    const Node* Search(const std::string& _name);

    uint32_t Root()
    {
        return root->data.second;
    }
private:
    Node* root {nullptr};

    const Node* Insert(Node* _node,
                       const std::string& _name,
                       uint32_t _id);
};
