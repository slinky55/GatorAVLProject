#include "BST.h"

/*
 * API
 */
const Node* BST::Insert(const std::string& _name,
                        uint32_t _id)
{
    return Insert(root,
                  _name,
                  _id);
}

/*
 * Private utility functions
 */
const Node* BST::Insert(Node* _node,
                        const std::string& _name,
                        uint32_t _id)
{
    if (_node == nullptr)
    {
        _node = new Node;
        _node->data = DataPair{_name, _id};
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
