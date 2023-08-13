#include <iostream>
#include <stdbool.h>
#include <algorithm>
#include <assert.h>
#include "reverse_iterator.h"
#include <windows.h>
using namespace std;

namespace Jeffrey
{
    template <class T>
    struct list_node
    {
        struct list_node *_prev;
        struct list_node *_next;
        T _val;

        list_node(const T &x = T())
            : _prev(nullptr), _next(nullptr), _val(x)
        {
        }
    };

    template <class T, class Ref, class Ptr>
    struct __list_iterator
    {
    public:
        // 使用 find 算法得加
        typedef bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef Ptr pointer;
        typedef Ref reference;
        typedef ptrdiff_t difference_type;

        typedef list_node<T> Node;
        typedef __list_iterator<T, Ref, Ptr> iterator;
        __list_iterator(Node *node)
            : _node(node)
        {
        }
        bool operator==(const iterator &x) const
        {
            return _node == x._node;
        }
        bool operator!=(const iterator &x) const
        {
            return _node != x._node;
        }
        Ref operator*() const
        {
            return _node->_val;
        }
        Ptr operator->() const
        {
            return &(operator*());
        }
        iterator &operator++()
        {
            _node = _node->_next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator tmp = *this;
            _node = _node->_next;
            return tmp;
        }
        iterator &operator--()
        {
            _node = _node->_prev;
            return *this;
        }
        iterator operator--(int)
        {
            iterator tmp = *this;
            _node = _node->_prev;
            return tmp;
        }

        Node *_node;
    };

    template <class T>
    class list
    {
    public:
        typedef list_node<T> Node;
        typedef __list_iterator<T, T &, T *> iterator;
        typedef __list_iterator<T, const T &, const T *> const_iterator;
        typedef __reverse_iterator<iterator, T &, T *> reverse_iterator;
        typedef __reverse_iterator<const_iterator, const T &, const T *> const_reverse_iterator;

        iterator begin()
        {
            return iterator(_head->_next);
        }
        iterator end()
        {
            return iterator(_head);
        }

        const_iterator begin() const
        {
            return const_iterator(_head->next);
        }
        const_iterator end() const
        {
            return const_iterator(_head);
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }
        list()
        {
            _head = new Node;
            _head->_next = _head->_prev = _head;
        }
        void push_back(const T &x)
        {
            Node *newnode = new Node(x);
            Node *tail = _head->_prev;
            tail->_next = newnode;
            newnode->_prev = tail;
            newnode->_next = _head;
            _head->_prev = newnode;
        }
        void push_front(const T &x)
        {
            Node *newnode = new Node(x);
            Node *next = _head->_next;
            _head->_next = newnode;
            newnode->_prev = _head;
            newnode->_next = next;
            next->_prev = newnode;
        }
        iterator insert(iterator pos, const T &x)
        {
            Node *newnode = new Node(x);
            Node *prev = pos._node->_prev;
            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = pos._node;
            pos._node->_prev = newnode;
            return iterator(newnode);
        }
        bool empty() const
        {
            return _head->_next == _head->_prev;
        }
        void pop_back()
        {
            assert(!empty());
            Node *tail = _head->_prev;
            Node *newtail = tail->_prev;
            delete tail;
            _head->_prev = newtail;
            newtail->_next = _head;
        }
        void pop_front()
        {
            Node *head = _head->_next;
            Node *newhead = head->_next;
            delete head;
            _head->_next = newhead;
            newhead->_prev = _head;
        }
        iterator erase(iterator pos)
        {
            assert(pos._node != _head);
            Node *prev = pos._node->_prev;
            Node *next = pos._node->_next;
            delete pos._node;
            prev->_next = next;
            next->_prev = prev;
            return (++pos);
        }

    private:
        Node *_head;
    };

    void test_list()
    {
        list<int> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        l.push_back(4);
        l.push_back(5);
        l.push_front(0);
        l.push_front(-1);
        l.insert(find(l.begin(), l.end(), 4), 3);
        l.insert(find(l.begin(), l.end(), 3), 0);
        l.pop_back();
        l.pop_front();
        l.pop_back();
        l.pop_front();
        l.pop_back();
        l.pop_back();
        l.pop_front();
        l.erase(find(l.begin(), l.end(), 2));
        l.push_front(1);
        l.erase(find(l.begin(), l.end(), 0));

        for (auto &e : l)
            cout << e << " ";
        cout << endl;
    }
    void test_list_reverse_iterator()
    {
        list<int> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        l.push_back(4);
        l.push_back(5);
        auto rit = l.rbegin();
        while(rit!=l.rend())
        {
            cout << *rit << " ";
            rit++;
        }
        cout << endl;
    }
};