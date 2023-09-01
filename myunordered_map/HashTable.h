#pragma once

#include <iostream>
#include <assert.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

using namespace std;

namespace Jeffrey
{

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

    template <class Key, class T, class Hash, class getKey>
    class HashTable;

    template <class Key, class T, class Hash, class getKey>
    struct __Hash_Iterator
    {
        typedef HashTable<Key, T, Hash, getKey> HashTable;
        typedef Node<T> Node;
        typedef __Hash_Iterator<Key, T, Hash, getKey> Self;
        const HashTable *_pht;
        Node *_node;

        __Hash_Iterator(const HashTable *pht,  Node *node)
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
                getKey gk;
                size_t hashi = hs(gk(_node->_data)) % _pht->TableSize();
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
        T &operator*() const 
        {
            return _node->_data;
        }
        T *operator->() const
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

    template <class Key, class T, class Hash, class getKey>
    class HashTable
    {
    public:
        friend struct __Hash_Iterator<Key, T, Hash, getKey>;

        typedef __Hash_Iterator<Key, T, Hash, getKey> iterator;
        typedef Node<T> Node;

        inline size_t __stl_next_prime(size_t n)
        {
            static const size_t __stl_num_primes = 28;
            static const size_t __stl_prime_list[__stl_num_primes] =
                {
                    53, 97, 193, 389, 769,
                    1543, 3079, 6151, 12289, 24593,
                    49157, 98317, 196613, 393241, 786433,
                    1572869, 3145739, 6291469, 12582917, 25165843,
                    50331653, 100663319, 201326611, 402653189, 805306457,
                    1610612741, 3221225473, 4294967291};

            for (size_t i = 0; i < __stl_num_primes; ++i)
            {
                if (__stl_prime_list[i] > n)
                {
                    return __stl_prime_list[i];
                }
            }
            return -1;
        }

        iterator begin() const 
        {
            for (size_t i = 0; i < _table.size(); i++)
            {
                if (_table[i])
                    return iterator(this, _table[i]);
            }
            return end();
        }
        iterator end() const 
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
        iterator find(const Key &key) const
        {
            if (_table.size() == 0)
                return end();
            Hash hs;
            size_t hashi = hs(key) % _table.size();
            if (_table[hashi] == nullptr)
                return end();
            Node *cur = _table[hashi];
            while (cur)
            {
                getKey gt;
                if (gt(cur->_data) == key)
                    return iterator(this, cur);
                cur = cur->_next;
            }
            return end();
        }
        pair<iterator, bool> insert(const T &data)
        {
            auto ret = find(getKey()(data));
            if (ret!= end())
                return make_pair(ret, false);
            else
            {
                // 扩容
                if (_size == _table.size())
                {
                    size_t newsize = __stl_next_prime(_size);
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
                            getKey gt;
                            size_t hashi = hs(gt(cur->_data)) % _table.size();
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
                getKey gt;
                size_t hashi = hs(gt(data)) % _table.size();
                newnode->_next = _table[hashi];
                _table[hashi] = newnode;
                _size++;
                return make_pair(iterator(this,newnode),true);
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
                getKey gt;
                while (gt(cur->_data) != key)
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
                        getKey gt;
                        cout << "--> [" << gt(cur->_data) << "]";
                        cur = cur->_next;
                    }
                    cout << endl;
                }
            }
        }
        void resize(size_t n) 
        {
            _table.resize(n);
        }
        size_t size() const
        {
            return _size;
        }
        size_t BucketSize() const 
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
