#pragma once

#include <iostream>
#include <windows.h>
#include <stdbool.h>
#include <assert.h>
using namespace std;

namespace Jeffrey
{
    template <class K>
    struct BSTNode
    {

        BSTNode *_left;
        BSTNode *_right;
        K _key;

        BSTNode(const K &key)
            : _key(key), _left(nullptr), _right(nullptr)
        {
        }
    };

    template <class K>
    class BSTree
    {
        typedef BSTNode<K> Node;

    public:
        
        bool insert(const K &key)
        {
            if (_root == nullptr)
            {
                _root = new Node(key);
                return true;
            }
            Node *cur = _root;
            Node *parent = nullptr;
            while (cur)
            {
                if (cur->_key < key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (cur->_key > key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else
                    return false;
            }
            cur = new Node(key);
            if (parent->_key > key)
                parent->_left = cur;
            else
                parent->_right = cur;
            return true;
        }
        void Inorder() const
        {
            _Inorder(_root);
            cout << endl;
        }
        bool find(const K &key) const
        {
            Node *cur = _root;
            while (cur)
            {
                if (cur->_key < key)
                    cur = cur->_right;
                else if (cur->_key > key)
                    cur = cur->_left;
                else
                    return true;
            }
            return false;
        }
        bool erase(const K &key)
        {
            Node *cur = _root;
            Node *parent = nullptr;
            while (cur)
            {
                if (cur->_key < key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (cur->_key > key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else // 删除节点
                {
                    Node *del = cur;
                    if (cur->_left == nullptr) // 删除节点左树为空，父节点托管右树
                    {
                        if (parent == nullptr)
                            _root = cur->_right;
                        else
                        {
                            if (parent->_left == cur)
                                parent->_left = cur->_right;
                            else
                                parent->_right = cur->_right;
                        }
                    }
                    else if (cur->_right == nullptr) // 删除节点右树为空，父节点托管左树
                    {
                        if (parent == nullptr)
                            _root = cur->_left;
                        else
                        {
                            if (parent->_left == cur)
                                parent->_left = cur->_left;
                            else
                                parent->_right = cur->_left;
                        }
                    }
                    else // 删除节点左右子树都不为空，替换删除法，找左子树最右节点或右子树最左节点
                    {
                        Node *submin = cur->_right;
                        Node *psubmin = cur;
                        while (submin->_left)
                        {
                            psubmin = submin;
                            submin = submin->_left;
                        }
                        ::swap(cur->_key, submin->_key);
                        // 删除右子树最左节点：该节点左为空，让父节点托管右树
                        if (psubmin == cur)
                            psubmin->_right = submin->_right;
                        else
                            psubmin->_left = submin->_right;
                        del = submin;
                    }
                    delete del;
                    return true;
                }
            }
            return false;
        }
        bool findR(const K &key) const
        {
            return _findR(_root, key);
        }
        bool insertR(const K &key)
        {
            return _insertR(_root, key);
        }
        bool eraseR(const K &key)
        {
            return _eraseR(_root, key);
        }
        BSTree(){};
        BSTree(const BSTree<K> &t)
        {
            _root = _copy(t._root);
        }
        BSTree<K> & operator=(BSTree<K> t)
        {
            ::swap(_root, t._root);
            return *this;
        }
        ~BSTree()
        {
            _destroy(_root);
        }
    private:
        Node *_root = nullptr;
        void _destroy(Node* root)
        {
            if(root==nullptr)
                return;
            _destroy(root->_left);
            _destroy(root->_right);
            delete root;
        }
        Node* _copy(Node* root)
        {
            if(root==nullptr)
                return nullptr;
            Node *newroot = new Node(root->_key);
            newroot->_left = _copy(root->_left);
            newroot->_right = _copy(root->_right);
            return newroot;
        }
        void _Inorder(Node *root) const
        {
            if (root == nullptr)
                return;
            _Inorder(root->_left);
            cout << root->_key << " ";
            _Inorder(root->_right);
        }
        bool _findR(Node *root, const K &key) const
        {
            if (root == nullptr)
                return false;
            if (root->_key == key)
                return true;
            return _findR(root->_left, key) || _findR(root->_right, key);
        }
        bool _insertR(Node *&root, const K &key)
        {
            if (root == nullptr)
            {
                root = new Node(key);
                return true;
            }
            if (root->_key < key)
                return _insertR(root->_right, key);
            else if (root->_key > key)
                return _insertR(root->_left, key);
            else
                return false;
        }
        bool _eraseR(Node *&root, const K &key)
        {
            if (root == nullptr)
                return false;
            if (root->_key < key)
                return _eraseR(root->_right, key);
            else if (root->_key > key)
                return _eraseR(root->_left, key);
            else
            {
                if (root->_left == nullptr)
                {
                    root = root->_right;
                    return true;
                }
                else if (root->_right == nullptr)
                {
                    root = root->_left;
                    return true;
                }
                else
                {
                    Node *submin = root->_right;
                    while (submin->_left)
                        submin = submin->_left;
                    ::swap(root->_key, submin->_key);
                    return _eraseR(root->_right, key);
                }
            }
        }
    };
};