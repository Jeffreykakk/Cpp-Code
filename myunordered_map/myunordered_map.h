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

    template <class Key, class Value>
    class unordered_map
    {
    public:
        struct getKey
        {
            const Key &operator()(const pair<Key, Value> &kv)
            {
                return kv.first;
            }
        };
        typedef typename Jeffrey::HashTable<Key, pair<Key, Value>, HashFunc<Key>, getKey>::iterator iterator;
        iterator begin()
        {
            return _ht.begin();
        }
        iterator end()
        {
            return _ht.end();
        }
        pair<iterator, bool> insert(const pair<Key, Value> &kv)
        {
            return _ht.insert(kv);
        }
        Value &operator[](const Key &key)
        {
            auto ret = insert(make_pair(key, Value()));
            return ret.first->second;
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
        Jeffrey::HashTable<Key, pair<Key, Value>, HashFunc<Key>, getKey> _ht;
    };

    void test1()
    {
        unordered_map<int, int> m;
        m.insert(make_pair(1, 1));
        m.insert(make_pair(11, 1));
        m.insert(make_pair(12, 1));
        m.insert(make_pair(2, 1));
        m.insert(make_pair(4, 1));
        m.insert(make_pair(6, 1));
        m.insert(make_pair(18, 1));
        m.insert(make_pair(48, 1));
        m.insert(make_pair(28, 1));
        m.insert(make_pair(5, 1));
        m.insert(make_pair(25, 1));
        m.print();
        cout << "-----------------------------------------" << endl;
        for (auto &e : m)
            cout << e.first << ":" << e.second << endl;
    }
    void test2()
    {
        unordered_map<string, int> countmap;
        const char *arr[] = {"apple", "pine", "pine", "banana", "apple"};
        for (auto &e : arr)
            countmap[e]++;
        for (auto &e : countmap)
            cout << e.first << ":" << e.second << endl;
    }
};