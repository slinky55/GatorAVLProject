#pragma once

#include <iostream>
#include <string>
#include <vector>

using DataPair = std::pair<std::string, uint32_t>;

struct Node
{
    Node* left;
    Node* right;
    uint32_t height;

    DataPair data;
};

class AVL {
public:
    AVL() = default;

    void Insert(const DataPair &_data);
    void Remove(uint32_t _data);
    Node* Search(uint32_t _id);
    void Search(const std::string &_name,
                std::vector<Node*> _list);
    void RemoveInOrder(uint32_t n);
    void Height();

    void PrintInOrder();
    void PrintPreOrder();
    void PrintPostOrder();

private:
    Node* root {nullptr};

    Node* Insert(const DataPair &_data,
                 Node* _t);
    Node* Search(uint32_t _id,
                 Node* _node);
    void Search(const std::string &_name,
                Node* _node,
                std::vector<Node*> &_list);
    Node* Remove(uint32_t _data,
                 Node* _t);
    void Empty(Node* _t);

    Node* SingleRightRotate(Node*& _t);
    Node* SingleLeftRotate(Node*& _t);
    Node* DoubleLeftRotate(Node*& _t);
    Node* DoubleRightRotate(Node*& _t);

    Node* FindMin(Node* _t);
    Node* FindMax(Node* _t);

    uint32_t Height(Node* _t);
    int GetBalance(Node* _t);

    Node* RemoveInOrder(uint32_t n,
                        uint32_t m,
                        Node* _t);
    void InOrder(Node* _node);
    void PostOrder(Node* _node);
    void PreOrder(Node* _node);
};