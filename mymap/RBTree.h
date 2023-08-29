#pragma once

#include <iostream>
#include <assert.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

using namespace std;

enum Colour
{
    RED,
    BLACK
};

namespace Jeffrey
{
    template <class T>
    struct RBTreeNode
    {
        typedef RBTreeNode<T> Node;
        RBTreeNode(const T &data)
            : _left(nullptr), _right(nullptr), _parent(nullptr), _data(data), _col(RED)
        {
        }

        Node *_left;
        Node *_right;
        Node *_parent;
        T _data;
        Colour _col;
    };

    template <class T, class Ref, class Ptr>
    struct __RBTree_Iterator
    {
        typedef RBTreeNode<T> Node;
        typedef __RBTree_Iterator<T, Ref, Ptr> _RBTree_Iterator;
        __RBTree_Iterator(Node *node)
            : _node(node)
        {
        }
        Ref operator*() const
        {
            return _node->_data;
        }
        Ptr operator->() const
        {
            return &(_node->_data);
        }
        bool operator==(const _RBTree_Iterator &it) const
        {
            return _node == it._node;
        }
        bool operator!=(const _RBTree_Iterator &it) const
        {
            return _node != it._node;
        }
        _RBTree_Iterator operator++()
        {
            if (_node->_right)
            {
                _node = _node->_right;
                while (_node->_left)
                    _node = _node->_left;
                return *this;
            }
            else
            {
                Node *parent = _node->_parent;
                while (parent && parent->_left != _node)
                {
                    _node = parent;
                    parent = _node->_parent;
                }
                _node = parent;
                return *this;
            }
        }
        _RBTree_Iterator operator--()
        {
            if (_node->_left)
            {
                _node = _node->_left;
                while (_node->_right)
                    _node = _node->_right;
                return *this;
            }
            else
            {
                Node *parent = _node->_parent;
                while (parent && parent->_right != _node)
                {
                    _node = parent;
                    parent = _node->_parent;
                }
                _node = parent;
                return *this;
            }
        }

    private:
        Node *_node;
    };

    template <class Key, class T, class getKey>
    class RBTree
    {
    public:
        typedef RBTreeNode<T> Node;
        typedef __RBTree_Iterator<T, T &, T *> iterator;
        iterator begin() const
        {
            if (_root == nullptr)
                return iterator(nullptr);
            Node *cur = _root;
            while (cur->_left)
                cur = cur->_left;
            return iterator(cur);
        }
        iterator end() const
        {
            return iterator(nullptr);
        }
        RBTree()
        {
        }
        ~RBTree()
        {
            _Destroy(_root);
        }
        pair<iterator, bool> Insert(const T &data)
        {
            if (_root == nullptr)
            {
                _root = new Node(data);
                _root->_col = BLACK;
                return make_pair(iterator(_root), true);
            }
            Node *cur = _root;
            Node *parent = nullptr;
            while (cur)
            {
                getKey gt;
                if (gt(cur->_data) > gt(data))
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if (gt(cur->_data) < gt(data))
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else
                    return make_pair(iterator(cur), false);
            }
            // 插入
            getKey gt;
            cur = new Node(data);
            if (gt(data) < gt(parent->_data))
            {
                parent->_left = cur;
                cur->_parent = parent;
            }
            else
            {
                parent->_right = cur;
                cur->_parent = parent;
            }
            while (parent && parent->_col == RED)
            {
                Node *grand = parent->_parent;
                if (grand->_left == parent)
                {
                    Node *uncle = grand->_right;
                    // 叔叔存在且为红，染色并向上更新
                    if (uncle && uncle->_col == RED)
                    {
                        parent->_col = uncle->_col = BLACK;
                        grand->_col = RED;
                        cur = grand;
                        parent = cur->_parent;
                    }
                    // 叔叔不存在或叔叔存在且为黑，旋转
                    else if (uncle == nullptr || uncle->_col == BLACK)
                    {
                        if (parent == grand->_left)
                        {
                            // 右单旋
                            if (cur == parent->_left)
                            {
                                RotateR(grand);
                                parent->_col = BLACK;
                                grand->_col = RED;
                            }
                            else
                            {
                                // 左右双旋
                                RotateL(parent);
                                RotateR(grand);
                                cur->_col = BLACK;
                                grand->_col = RED;
                            }
                        }
                        else
                        {
                            if (cur == parent->_right)
                            {
                                // 左单旋
                                RotateL(grand);
                                parent->_col = BLACK;
                                grand->_col = RED;
                            }
                            else
                            {
                                // 右左双旋
                                RotateR(parent);
                                RotateL(grand);
                                cur->_col = BLACK;
                                grand->_col = RED;
                            }
                        }
                        break;
                    }
                }
                else
                {
                    Node *uncle = grand->_left;
                    // 叔叔存在且为红，染色并向上更新
                    if (uncle && uncle->_col == RED)
                    {
                        parent->_col = uncle->_col = BLACK;
                        grand->_col = RED;
                        cur = grand;
                        parent = cur->_parent;
                    }
                    // 叔叔不存在或叔叔存在且为黑，旋转
                    else if (uncle == nullptr || uncle->_col == BLACK)
                    {
                        if (parent == grand->_left)
                        {
                            // 右单旋
                            if (cur == parent->_left)
                            {
                                RotateR(grand);
                                parent->_col = BLACK;
                                grand->_col = RED;
                            }
                            else
                            {
                                // 左右双旋
                                RotateL(parent);
                                RotateR(grand);
                                cur->_col = BLACK;
                                grand->_col = RED;
                            }
                        }
                        else
                        {
                            if (cur == parent->_right)
                            {
                                // 左单旋
                                RotateL(grand);
                                parent->_col = BLACK;
                                grand->_col = RED;
                            }
                            else
                            {
                                // 右左双旋
                                RotateR(parent);
                                RotateL(grand);
                                cur->_col = BLACK;
                                grand->_col = RED;
                            }
                        }
                        break;
                    }
                }
            }

            if (_root->_col == RED)
                _root->_col = BLACK;
            return make_pair(iterator(cur), true);
        }
        bool IsRBTree() const
        {
            if (_root == nullptr)
                return true;
            if (_root->_col == RED)
                return false;
            int benchmark = 0;
            return prevcheck(_root, 0, benchmark);
        }
        void Inorder() const
        {
            _Inorder(_root);
            cout << endl;
        }

    private:
        void _Destroy(Node *root)
        {
            if (root == nullptr)
                return;
            _Destroy(root->_left);
            _Destroy(root->_right);
            delete root;
        }
        bool prevcheck(Node *root, int blackcount, int &benchmark) const
        {
            if (root == nullptr)
            {
                if (benchmark == 0)
                {
                    benchmark = blackcount;
                    return true;
                }
                if (blackcount == benchmark)
                    return true;
                else
                    return false;
            }
            if (root->_col == BLACK)
                blackcount++;
            if (root->_col == RED && root->_parent->_col == RED)
                return false;
            return prevcheck(root->_left, blackcount, benchmark) && prevcheck(root->_right, blackcount, benchmark);
        }
        void _Inorder(Node *root) const
        {
            if (root == nullptr)
                return;
            _Inorder(root->_left);
            cout << root->_kv.first << " ";
            _Inorder(root->_right);
        }
        void RotateR(Node *parent)
        {
            Node *subL = parent->_left;
            Node *subLR = subL->_right;
            Node *grand = parent->_parent;
            parent->_left = subLR;
            if (subLR)
                subLR->_parent = parent;
            subL->_right = parent;
            parent->_parent = subL;
            if (grand == nullptr)
            {
                _root = subL;
                subL->_parent = nullptr;
            }
            else
            {
                if (grand->_left == parent)
                    grand->_left = subL;
                else
                    grand->_right = subL;
                subL->_parent = grand;
            }
        }
        void RotateL(Node *parent)
        {
            Node *subR = parent->_right;
            Node *subRL = subR->_left;
            Node *grand = parent->_parent;
            parent->_right = subRL;
            if (subRL)
                subRL->_parent = parent;
            subR->_left = parent;
            parent->_parent = subR;
            if (grand == nullptr)
            {
                _root = subR;
                subR->_parent = nullptr;
            }
            else
            {
                if (grand->_left == parent)
                    grand->_left = subR;
                else
                    grand->_right = subR;
                subR->_parent = grand;
            }
        }
        Node *_root = nullptr;
    };
};