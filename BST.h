#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

using DataPair = std::pair<std::string, uint32_t>;

struct node
{
    node* left;
    node* right;
    uint32_t height;

    DataPair data;
};

class BST {
    node *root;

    void makeEmpty(node *t) {
        if (t == nullptr)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    node *insert(const DataPair &_data, node *t) {
        if (t == nullptr) {
            t = new node;
            t->data = _data;
            t->height = 0;
            t->left = t->right = nullptr;
            std::cout << "successful\n";
        } else if (_data.second < t->data.second) {
            t->left = insert(_data, t->left);
            if (height(t->left) - height(t->right) == 2) {
                if (_data.second < t->left->data.second)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        } else if (_data.second > t->data.second) {
            t->right = insert(_data, t->right);
            if (height(t->right) - height(t->left) == 2) {
                if (_data > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right)) + 1;
        return t;
    }

    node *singleRightRotate(node *&t) {
        node *u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(u->left), t->height) + 1;
        return u;
    }

    node *singleLeftRotate(node *&t) {
        node *u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(t->right), t->height) + 1;
        return u;
    }

    node *doubleLeftRotate(node *&t) {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node *doubleRightRotate(node *&t) {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node *findMin(node *t) {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    node *findMax(node *t) {
        if (t == nullptr)
            return nullptr;
        else if (t->right == nullptr)
            return t;
        else
            return findMax(t->right);
    }

    node *remove(uint32_t _data, node *t) {
        node *temp;

        // Element not found
        if (t == nullptr) {
            std::cout << "unsuccessful\n";
            return nullptr;
        }
            // Searching for element
        else if (_data < t->data.second)
            t->left = remove(_data, t->left);
        else if (_data > t->data.second)
            t->right = remove(_data, t->right);

            // Element found
            // With 2 children
        else if (t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data.second, t->right);
            std::cout << "successful\n";
        }
            // With one or zero child
        else {
            temp = t;
            if (t->left == nullptr)
                t = t->right;
            else if (t->right == nullptr)
                t = t->left;
            delete temp;
            std::cout << "successful\n";
        }
        if (t == nullptr)
            return t;

        t->height = max(height(t->left), height(t->right)) + 1;

        // If node is unbalanced
        // If left node is deleted, right case
        if (height(t->left) - height(t->right) == 2) {
            // right right case
            if (height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
                // right left case
            else
                return doubleLeftRotate(t);
        }
            // If right node is deleted, left case
        else if (height(t->right) - height(t->left) == 2) {
            // left left case
            if (height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
                // left right case
            else
                return doubleRightRotate(t);
        }
        return t;
    }

    uint32_t height(node *t) {
        return (t == nullptr ? 0 : t->height);
    }

    int getBalance(node *t) {
        if (t == nullptr)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    node *RemoveInOrder(uint32_t n,
                        uint32_t m,
                        node *t) {
        if (m == n)
            return remove(t->data.second, t);
    }

    node *Search(uint32_t _id,
                 node *_node) {
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

    void Search(const std::string &_name,
                node *_node,
                std::vector<node *> &_list) {
        if (_node == nullptr)
            return;
        Search(_name, _node->left, _list);
        if (_node->data.first == _name)
            _list.emplace_back(_node);
        Search(_name, _node->right, _list);
    }

    void inorder(node* _node) {
        if (_node == nullptr)
            return;
        inorder(_node->left);
        cout << _node->data.first << ", ";
        inorder(_node->right);
    }

    void postorder(node* _node)
    {
        if (_node == nullptr)
            return;
        postorder(_node->left);
        postorder(_node->right);
        cout << _node->data.first << ", ";
    }

    void preorder(node* _node)
    {
        if (_node == nullptr)
            return;
        cout << _node->data.first << ", ";
        preorder(_node->left);
        preorder(_node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(const DataPair &_data) {
        root = insert(_data, root);
    }

    void remove(uint32_t _data) {
        root = remove(_data, root);
    }

    node *Search(uint32_t _id) {
        return Search(_id, root);
    }

    void Search(const std::string &_name,
                std::vector<node *> _list) {
        Search(_name, root, _list);
    }

    void RemoveInOrder(uint32_t n) {
        root = RemoveInOrder(n, 0, root);
    }

    void levelCount() {
        cout << height(root);
    }

    void printInorder() {
        inorder(root);
        cout << "\n";
    }

    void printPreorder()
    {
        preorder(root);
        cout << "\n";
    }

    void printPostorder()
    {
        postorder(root);
        cout << "\n";
    }
};