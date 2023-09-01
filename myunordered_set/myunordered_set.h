#pragma once

#include "HashTable.h"

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

    template <class Key>
    class unordered_set
    {
    public:
        struct getKey
        {
            const Key &operator()(const Key &key)
            {
                return key;
            }
        };
        typedef typename Jeffrey::HashTable<Key, Key, HashFunc<Key>, getKey>::iterator iterator;
        iterator begin()
        {
            return _ht.begin();
        }
        iterator end()
        {
            return _ht.end();
        }
        pair<iterator, bool> insert(const Key &key)
        {
            return _ht.insert(key);
        }
        iterator find(const Key &key)
        {
            return _ht.find(key);
        }
        bool erase(const Key &key)
        {
            return _ht.erase;
        }
        void print()
        {
            _ht.print();
        }
        void resize(size_t n)
        {
            _ht.resize(n);
        }
        size_t size() const
        {
            return _ht.size();
        }
        size_t BucketSize() const
        {
            return _ht.BucketSize();
        }
        size_t TableSize() const
        {
            return _ht.TableSize();
        }
        size_t MaxBucketLength() const
        {
            return _ht.MaxBucketLength;
        }

    private:
        Jeffrey::HashTable<Key, Key, HashFunc<Key>, getKey> _ht;
    };

    void test()
    {
        unordered_set<int> s1;
        s1.insert(12);
        s1.insert(2);
        s1.insert(22);
        unordered_set<int> s2;
        s2.insert(12);
        s2.insert(2);
        s2.insert(22);
        auto it = s1.begin();
        cout << *it << endl;
        it = s2.begin();
        ++it;
        cout << *it << endl;
        s1.print();
    }
};