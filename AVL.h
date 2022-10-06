#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <utility>
#include <memory>

using DataPair = std::pair<std::string, uint32_t>;

struct Node;
using NodePtr = std::shared_ptr<Node>;

struct Node
{
    Node* left;
    Node* right;

    DataPair data;
};

class AVL
{
public:
    AVL() = default;

    Node* Insert(const std::string& _name,
                  uint32_t _id);

    Node* Search(uint32_t _id);
    Node* Search(const std::string& _name);

private:
    Node* root {nullptr};

    Node* Insert(Node*& _node,
                  const std::string& _name,
                  uint32_t _id);

    Node* Search(Node*& _node,
                  uint32_t _id);
    Node* Search(Node*& _node,
                 const std::string& _name);
};
