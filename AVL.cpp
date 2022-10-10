#include "AVL.h"

/*
 *  API
 */

void AVL::Insert(const DataPair &_data)
{
    root = Insert(_data, root);
}

void AVL::Remove(uint32_t _data)
{
    root = Remove(_data, root);
}

Node* AVL::Search(uint32_t _id)
{
    return Search(_id, root);
}

void AVL::Search(const std::string &_name,
            std::vector<Node*> _list)
{
    Search(_name, root, _list);
}

void AVL::RemoveInOrder(uint32_t n)
{
    root = RemoveInOrder(n, 0, root);
}

void AVL::Height()
{
    std::cout << Height(root);
}

void AVL::PrintInOrder()
{
    InOrder(root);
    std::cout << "\n";
}

void AVL::PrintPreOrder()
{
    PreOrder(root);
    std::cout << "\n";
}

void AVL::PrintPostOrder()
{
    PostOrder(root);
    std::cout << "\n";
}


/*
 *  Private utility functions
 */
Node* AVL::Insert(const DataPair &_data, Node* _t)
{
    if (_t == nullptr) {
        _t = new Node;
        _t->data = _data;
        _t->height = 0;
        _t->left = _t->right = nullptr;
        std::cout << "successful\n";
    } else if (_data.second < _t->data.second) {
        _t->left = Insert(_data, _t->left);
        if (Height(_t->left) - Height(_t->right) == 2) {
            if (_data.second < _t->left->data.second)
                _t = SingleRightRotate(_t);
            else
                _t = DoubleRightRotate(_t);
        }
    } else if (_data.second > _t->data.second) {
        _t->right = Insert(_data, _t->right);
        if (Height(_t->right) - Height(_t->left) == 2) {
            if (_data > _t->right->data)
                _t = SingleLeftRotate(_t);
            else
                _t = DoubleLeftRotate(_t);
        }
    }

    _t->height = std::max(Height(_t->left), Height(_t->right)) + 1;
    return _t;
}
Node* AVL::Search(uint32_t _id,
             Node* _node)
 {
    if (!_node)
        return nullptr;
    if (_id == _node->data.second) {
        std::cout << _node->data.first << "\n";
        return _node;
    }
    if (_id < _node->data.second)
        return Search(_id,
                      _node->left);
    if (_id > _node->data.second)
        return Search(_id,
                      _node->right);
    return nullptr;
}
void AVL::Search(const std::string &_name,
            Node* _node,
            std::vector<Node*> &_list)
{
    if (_node == nullptr)
        return;
    Search(_name, _node->left, _list);
    if (_node->data.first == _name)
        _list.emplace_back(_node);
    Search(_name, _node->right, _list);
}
Node* AVL::Remove(uint32_t _data,
             Node* _t)
 {
    Node* temp;

    // Element not found
    if (_t == nullptr) {
        std::cout << "unsuccessful\n";
        return nullptr;
    }
        // Searching for element
    else if (_data < _t->data.second)
        _t->left = Remove(_data,
                          _t->left);
    else if (_data > _t->data.second)
        _t->right = Remove(_data,
                           _t->right);

        // Element found
        // With 2 children
    else if (_t->left && _t->right) {
        temp = FindMin(_t->right);
        _t->data = temp->data;
        _t->right = Remove(_t->data.second,
                           _t->right);
        std::cout << "successful\n";
    }
        // With one or zero child
    else {
        temp = _t;
        if (_t->left == nullptr)
            _t = _t->right;
        else if (_t->right == nullptr)
            _t = _t->left;
        delete temp;
        std::cout << "successful\n";
    }
    if (!_t)
        return _t;

    _t->height = std::max(Height(_t->left), Height(_t->right)) + 1;

    // If node is unbalanced
    // If left node is deleted, right case
    if (Height(_t->left) - Height(_t->right) == 2) {
        // right right case
        if (Height(_t->left->left) - Height(_t->left->right) == 1)
            return SingleLeftRotate(_t);
            // right left case
        else
            return DoubleLeftRotate(_t);
    }
        // If right node is deleted, left case
    else if (Height(_t->right) - Height(_t->left) == 2) {
        // left left case
        if (Height(_t->right->right) - Height(_t->right->left) == 1)
            return SingleRightRotate(_t);
            // left right case
        else
            return DoubleRightRotate(_t);
    }
    return _t;
}
void AVL::Empty(Node* _t)
{
    if (_t == nullptr)
        return;
    Empty(_t->left);
    Empty(_t->right);
    delete _t;
}

Node* AVL::SingleRightRotate(Node*& _t) {
    Node *u = _t->left;
    _t->left = u->right;
    u->right = _t;
    _t->height = std::max(Height(_t->left), Height(_t->right)) + 1;
    u->height = std::max(Height(u->left), _t->height) + 1;
    return u;
}
Node* AVL::SingleLeftRotate(Node*& _t) {
    Node* u = _t->right;
    _t->right = u->left;
    u->left = _t;
    _t->height = std::max(Height(_t->left), Height(_t->right)) + 1;
    u->height = std::max(Height(_t->right), _t->height) + 1;
    return u;
}
Node* AVL::DoubleLeftRotate(Node*& _t) {
    _t->right = SingleRightRotate(_t->right);
    return SingleLeftRotate(_t);
}
Node* AVL::DoubleRightRotate(Node*& _t) {
    _t->left = SingleLeftRotate(_t->left);
    return SingleRightRotate(_t);
}

Node* AVL::FindMin(Node* _t) {
    if (_t == nullptr)
        return nullptr;
    else if (_t->left == nullptr)
        return _t;
    else
        return FindMin(_t->left);
}
Node* AVL::FindMax(Node* _t) {
    if (_t == nullptr)
        return nullptr;
    else if (_t->right == nullptr)
        return _t;
    else
        return FindMax(_t->right);
}

uint32_t AVL::Height(Node* _t) {
    return (!_t ? 0 : _t->height);
}
int32_t AVL::GetBalance(Node* _t) {
    if (_t == nullptr)
        return 0;
    else
        return Height(_t->left) - Height(_t->right);
}

Node* AVL::RemoveInOrder(uint32_t n,
                    uint32_t m,
                    Node* _t) {
    if (m == n)
        return Remove(_t->data.second, _t);
}
void AVL::InOrder(Node* _node) {
    if (_node == nullptr)
        return;
    InOrder(_node->left);
    std::cout << _node->data.first << ", ";
    InOrder(_node->right);
}
void AVL::PostOrder(Node* _node)
{
    if (_node == nullptr)
        return;
    PostOrder(_node->left);
    PostOrder(_node->right);
    std::cout << _node->data.first << ", ";
}
void AVL::PreOrder(Node* _node)
{
    if (_node == nullptr)
        return;
    std::cout << _node->data.first << ", ";
    PreOrder(_node->left);
    PreOrder(_node->right);
}