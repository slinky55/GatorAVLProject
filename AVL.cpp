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
    return nullptr;
}

Node* AVL::Search(uint32_t _id)
{
    return Search(root,
           _id);
}
Node* AVL::Search(const std::string& _name)
{
    return Search(root,
                  _name);
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
    return nullptr;
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
    return nullptr;
}
Node* AVL::Search(Node*& _node,
                  const std::string& _name)
{

    if (_node->left)
        return Search(_node->left,
                      _name);

    if (_node->data.first == _name)
        return _node;

    if (_node->right)
        return Search(_node->right,
                      _name);
}