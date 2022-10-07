#include "AVL.h"

/*
 * API
 */
Node* AVL::Insert(const std::string& _name,
                   uint32_t _id)
{
    if (!Search(_id))
    {
        return Insert(_node,
                      _name,
                      _id);
    }
    return nullptr;
}
Node* AVL::Delete(uint32_t _id)
{
    return Delete(_node,
                  _id);
}
Node* AVL::Search(uint32_t _id)
{
    return Search(_node,
                  _id);
}
Node* AVL::Search(const std::string& _name)
{
    return Search(_node,
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
Node* AVL::Delete(Node*& _node,
                  uint32_t _id)
{
    if(!_node) return nullptr;
    // search for key node
    if(_node->data.second < _id) _node->right = Delete(_node->right, _id);
    else if(_node->data.second > _id) _node->left = Delete(_node->left, _id);
    else { // root -> val == key
        auto toDelete = _node;
        if(!_node->left || !_node->right)
            _node = _node->left ? _node->left : _node->right;
        else {
            auto cur = _node, par = _node;
            _node = _node->right;
            while(_node->left) par = _node, _node = _node->left;
            cur->data.second = _node->data.second;
            if(par->left == _node) par->left = _node->right;
            else par->right = _node->right;
            toDelete = _node;
            _node = cur;
        }
        delete toDelete;
    }
    return _node;
}
Node* AVL::Search(Node*& _node,
                  uint32_t _id) {

    if (!_node)
    {
        return nullptr;
    }
    if (_id == _node->data.second)
    {
        return _node;
    }
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
    if (!_node)
    {
        return nullptr;
    }
    if (_node->data.first == _name)
        return _node;
    if (_node->left)
        return Search(_node->left,
                      _name);
    if (_node->right)
        return Search(_node->right,
                      _name);
}