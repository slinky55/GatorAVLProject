#include "AVL.h"

/*
 * API
 */
Node* AVL::Insert(const std::string& _name,
                   uint32_t _id)
{
    if (!Search(_id))
        return Insert(root,
                      _name,
                      _id);
}

Node* AVL::Search(uint32_t _id)
{
    return Search(root,
           _id);
}

/*
 * Private utility functions
 */
Node* AVL::Insert(Node*& _node,
                   const std::string& _name,
                   uint32_t _id)
{
    // Base case
    if (_node == nullptr)
    {
        _node = new Node;
        _node->data = {_name, _id};
        return _node;
    }

    if (_id < _node->data.second)
    {
        return Insert(_node->left,
                      _name,
                      _id);
    }

    if (_id > _node->data.second)
    {
        return Insert(_node->right,
                      _name,
                      _id);
    }
}

Node* AVL::Search(Node*& _node,
                  uint32_t _id)
{

    if (_node == nullptr)
        return nullptr;
    if (_id == _node->data.second)
        return _node;
    if (_id < _node->data.second)
        return Search(_node->left,
                      _id);
    if (_id > _node->data.second)
        return Search(_node->right,
                      _id);
}
