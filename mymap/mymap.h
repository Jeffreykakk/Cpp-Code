#pragma once

#include "RBTree.h"
#include <string>
using namespace Jeffrey;

namespace Jeffrey
{
    template <class Key, class Value>
    class map
    {
    public:
        struct getKey
        {
            const Key &operator()(const pair<Key, Value> &data)
            {
                return data.first;
            }
        };
        typedef typename RBTree<Key, pair<Key, Value>, getKey>::iterator iterator;
        map()
        {
        }
        iterator begin() const
        {
            return _t.begin();
        }
        iterator end() const
        {
            return _t.end();
        }
        pair<iterator, bool> Insert(const pair<Key, Value> &kv)
        {
            return _t.Insert(kv);
        }
        Value &operator[](const Key &key)
        {
            auto ret = Insert(make_pair(key, Value()));
            return ret.first->second;
        }

    private:
        RBTree<Key, pair<Key, Value>, getKey> _t;
    };

    void test()
    {
        const char *s[] = {"apple", "banana", "apple", "banana", "pine"};
        Jeffrey::map<string, int> m;
        for (auto &e : s)
            m[e]++;
        for (auto &e : m)
            cout << e.first << ":" << e.second << endl;
    }
};