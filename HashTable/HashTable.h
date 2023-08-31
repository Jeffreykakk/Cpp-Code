#pragma once

#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <vector>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

using namespace std;

namespace Jeffrey
{

    template <class Key>
    struct HashFunc
    {
        size_t operator()(const Key &key)
        {
            return (size_t)key;
        }
    };
    template <>
    struct HashFunc<string>
    {
        size_t operator()(const string &key)
        {
            size_t val = 0;
            for (auto ch : key)
            {
                val *= 131;
                val += ch;
            }
            return val;
        }
    };

    template <class T>
    struct Node
    {
    public:
        Node(const T &data)
            : _data(data), _next(nullptr)
        {
        }

        Node *_next;
        T _data;
    };

    template <class Key, class Value, class Hash>
    class HashTable;

    template <class Key, class Value, class Hash>
    struct __Hash_Iterator
    {
        typedef HashTable<Key, Value, Hash> HashTable;
        typedef Node<pair<Key, Value>> Node;
        typedef __Hash_Iterator<Key, Value, Hash> Self;
        HashTable *_pht;
        Node *_node;

        __Hash_Iterator(HashTable *pht, Node *node)
            : _pht(pht), _node(node)
        {
        }

        Self &operator++()
        {
            if (_node->_next)
                _node = _node->_next;
            else
            {
                Hash hs;
                size_t hashi = hs(_node->_data.first) % _pht->TableSize();
                size_t i = 0;
                for (i = hashi + 1; i < _pht->_table.size(); i++)
                {
                    if (_pht->_table[i])
                        break;
                }
                if (i == _pht->_table.size())
                    _node = nullptr;
                else
                    _node = _pht->_table[i];
            }
            return *this;
        }
        Self operator++(int)
        {
            Self tmp = *this;
            ++(*this);
            return tmp;
        }
        pair<Key, Value> &operator*()
        {
            return _node->_data;
        }
        pair<Key, Value> *operator->()
        {
            return &(_node->_data);
        }
        bool operator==(const Self &it)
        {
            return _node == it._node;
        }
        bool operator!=(const Self &it)
        {
            return _node != it._node;
        }
    };

    template <class Key, class Value, class Hash = HashFunc<Key>>
    class HashTable
    {
    public:
        friend struct __Hash_Iterator<Key, Value, Hash>;

        typedef __Hash_Iterator<Key, Value, Hash> iterator;
        typedef Node<pair<Key, Value>> Node;

        iterator begin()
        {
            for (size_t i = 0; i < _table.size(); i++)
            {
                if (_table[i])
                    return iterator(this, _table[i]);
            }
            return end();
        }
        iterator end()
        {
            return iterator(this, nullptr);
        }
        ~HashTable()
        {
            for (size_t i = 0; i < _table.size(); i++)
            {
                if (_table[i])
                {
                    Node *cur = _table[i];
                    while (cur)
                    {
                        Node *next = cur->_next;
                        delete cur;
                        cur = next;
                    }
                    _table[i] = nullptr;
                }
            }
        }
        Node *find(const Key &key) const
        {
            if (_table.size() == 0)
                return nullptr;
            Hash hs;
            size_t hashi = hs(key) % _table.size();
            if (_table[hashi] == nullptr)
                return nullptr;
            Node *cur = _table[hashi];
            while (cur)
            {
                if (cur->_data.first == key)
                    return cur;
                cur = cur->_next;
            }
            return nullptr;
        }
        bool insert(const pair<Key, Value> &data)
        {
            if (find(data.first))
                return false;
            else
            {
                // 扩容
                if (_size == _table.size())
                {
                    size_t newsize = (_size == 0 ? 10 : _size * 2);
                    vector<Node *> newtable;
                    newtable.resize(newsize, nullptr);
                    _table.swap(newtable);
                    for (size_t i = 0; i < newtable.size(); i++)
                    {
                        Node *cur = newtable[i];
                        while (cur)
                        {
                            Node *next = cur->_next;
                            Hash hs;
                            size_t hashi = hs(cur->_data.first) % _table.size();
                            cur->_next = _table[hashi];
                            _table[hashi] = cur;
                            cur = next;
                        }
                        newtable[i] = nullptr;
                    }
                }
                // 插入
                Node *newnode = new Node(data);
                Hash hs;
                size_t hashi = hs(data.first) % _table.size();
                newnode->_next = _table[hashi];
                _table[hashi] = newnode;
                _size++;
                return true;
            }
        }
        bool erase(const Key &key)
        {
            if (_table.size() == 0)
                return false;
            Hash hs;
            size_t hashi = hs(key) % _table.size();
            if (_table[hashi] == nullptr)
                return false;
            else
            {
                Node *cur = _table[hashi];
                Node *prev = nullptr;
                while (cur->_data.first != key)
                {
                    prev = cur;
                    cur = cur->_next;
                }
                if (prev)
                    prev->_next = cur->_next;
                else
                    _table[hashi] = nullptr;
                delete cur;
                _size--;
                return true;
            }
        }
        void print() const
        {
            for (size_t i = 0; i < _table.size(); i++)
            {
                if (_table[i] == nullptr)
                    cout << i << " : --> nullptr" << endl;
                else
                {
                    Node *cur = _table[i];
                    cout << i << " : ";
                    while (cur)
                    {
                        cout << "--> [" << cur->_data.first << ":" << cur->_data.second << "]";
                        cur = cur->_next;
                    }
                    cout << endl;
                }
            }
        }
        void resize(size_t n) const
        {
            _table.resize(n);
        }
        size_t size() const
        {
            return _size;
        }
        size_t BucketSize()
        {
            size_t num = 0;
            for (size_t i = 0; i < _table.size(); i++)
            {
                if (_table[i])
                    ++num;
            }
            return num;
        }
        size_t TableSize() const
        {
            return _table.size();
        }
        size_t MaxBucketLength() const
        {
            size_t max = 0;
            for (size_t i = 0; i < _table.size(); i++)
            {
                size_t len = 0;
                if (_table[i])
                {
                    Node *cur = _table[i];
                    while (cur)
                    {
                        ++len;
                        cur = cur->_next;
                    }
                    if (len > max)
                        max = len;
                }
            }
            return max;
        }

    private:
        vector<Node *> _table;
        size_t _size = 0;
    };
};
