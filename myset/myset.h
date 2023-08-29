#pragma once

#include "RBTree.h"

using namespace Jeffrey;

namespace Jeffrey
{
    template <class Key>
    class set
    {
    public:
        
        struct getKey
        {
            const Key &operator()(const Key &data)
            {
                return data;
            }
        };
        typedef typename RBTree<Key, Key, getKey>::iterator iterator;
        set()
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
        pair<iterator,bool> Insert(const Key & key)
        {
            return _t.Insert(key);
        }
    private:
        RBTree<Key, Key, getKey> _t;
    };
};
