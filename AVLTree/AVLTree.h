#pragma once

#include <iostream>
#include <assert.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>
using namespace std;

namespace Jeffrey
{
    template <class Key, class Value>
    struct AVLTreeNode
    {
        typedef AVLTreeNode<Key, Value> Node;
        Node *_parent;
        Node *_left;
        Node *_right;
        pair<Key, Value> _kv;
        int _bf; // 平衡因子
        AVLTreeNode(const pair<Key, Value> &kv)
            : _parent(nullptr), _left(nullptr), _right(nullptr), _kv(kv), _bf(0)
        {
        }
    };

    template <class Key, class Value>
    class AVLTree
    {
    public:
        typedef AVLTreeNode<Key, Value> Node;
        AVLTree()
        {
        }
        bool Insert(const pair<Key, Value> &kv)
        {
            if (_root == nullptr)
            {
                _root = new Node(kv);
                return true;
            }
            Node *cur = _root;
            Node *parent = nullptr;
            while (cur)
            {
                if (cur->_kv.first > kv.first)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if (cur->_kv.first < kv.first)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else
                    return false;
            }

            // 插入
            cur = new Node(kv);
            if (parent->_kv.first > kv.first)
            {
                parent->_left = cur;
                cur->_parent = parent;
            }
            else
            {
                parent->_right = cur;
                cur->_parent = parent;
            }
            // 沿父路径更新平衡因子
            while (parent)
            {
                if (parent->_left == cur)
                    parent->_bf--;
                else
                    parent->_bf++;

                if (parent->_bf == 0)
                    break;
                else if (parent->_bf == -1 || parent->_bf == 1)
                {
                    cur = parent;
                    parent = parent->_parent;
                }
                else if (parent->_bf == -2 || parent->_bf == 2)
                {
                    // 旋转平衡二叉树
                    if (parent->_bf == -2 && cur->_bf == -1) // 右单旋
                        RotateR(parent);
                    else if (parent->_bf == 2 && cur->_bf == 1) // 左单旋
                        RotateL(parent);
                    else if (parent->_bf == -2 && cur->_bf == 1) // 左右双旋
                        RotateLR(parent);
                    else if (parent->_bf == 2 && cur->_bf == -1) // 右左双旋
                        RotateRL(parent);
                    else
                        assert(false);
                    break;
                }
            }
            return true;
        }
        bool Find(const Key key) const
        {
            Node *cur = _root;
            while (cur)
            {
                if (cur->_kv.first < key)
                    cur = cur->_right;
                else if (cur->_kv.first > key)
                    cur = cur->_left;
                else
                    return true;
            }
            return false;
        }
        void Inorder() const
        {
            _Inorder(_root);
        }
        bool isBalanced() const
        {
            return _isBalanced(_root);
        }

    private:
        Node *_root = nullptr;

        bool _isBalanced(Node *root) const
        {
            if (root == nullptr)
                return true;
            int leftHeight = Height(root->_left);
            int rightHeight = Height(root->_right);
            if (abs(leftHeight - rightHeight) >= 2)
                return false;
            return _isBalanced(root->_left) && _isBalanced(root->_right);
        }

        int Height(Node *root) const
        {
            if (root == nullptr)
                return 0;
            int leftHeight = Height(root->_left);
            int rightHeight = Height(root->_right);
            return max(leftHeight, rightHeight) + 1;
        }
        void _Inorder(Node *root) const
        {
            if (root == nullptr)
                return;
            _Inorder(root->_left);
            cout << root->_kv.first << " : " << root->_kv.second << endl;
            _Inorder(root->_right);
        }
        void RotateR(Node *parent)
        {
            Node *grand = parent->_parent;
            Node *subL = parent->_left;
            Node *subLR = subL->_right;
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
                {
                    grand->_left = subL;
                    subL->_parent = grand;
                }
                else
                {
                    grand->_right = subL;
                    subL->_parent = grand;
                }
            }
            // 更新平衡因子
            parent->_bf = 0;
            subL->_bf = 0;
        }
        void RotateL(Node *parent)
        {
            Node *grand = parent->_parent;
            Node *subR = parent->_right;
            Node *subRL = subR->_left;
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
                {
                    grand->_left = subR;
                    subR->_parent = grand;
                }
                else
                {
                    grand->_right = subR;
                    subR->_parent = grand;
                }
            }
            // 更新平衡因子
            parent->_bf = 0;
            subR->_bf = 0;
        }
        void RotateLR(Node *parent)
        {
            Node *subL = parent->_left;
            Node *subLR = subL->_right;
            int bf = subLR->_bf;
            RotateL(subL);
            RotateR(parent);
            subLR->_bf = 0;
            if (bf == 0)
            {
                parent->_bf = 0;
                subL->_bf = 0;
            }
            else if (bf == 1)
            {
                parent->_bf = 0;
                subL->_bf = -1;
            }
            else if (bf == -1)
            {
                parent->_bf = 1;
                subL->_bf = 0;
            }
            else
                assert(false);
        }
        void RotateRL(Node *parent)
        {
            Node *subR = parent->_right;
            Node *subRL = subR->_left;
            int bf = subRL->_bf;
            subRL->_bf = 0;
            RotateR(subR);
            RotateL(parent);
            if (bf == 0)
            {
                parent->_bf = 0;
                subR->_bf = 0;
            }
            else if (bf == 1)
            {
                parent->_bf = -1;
                subR->_bf = 0;
            }
            else if (bf == -1)
            {
                parent->_bf = 0;
                subR->_bf = 1;
            }
            else
                assert(false);
        }
    };
};
