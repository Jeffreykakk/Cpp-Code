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
    enum State
    {
        EMPTY,
        EXIST,
        ERASE
    };

    template <class Key>
    struct HashFunc
    {
        size_t operator()(const Key &key)
        {
            return (size_t)key;
        }
    };
    // 特化
    template <>
    struct HashFunc<string>
    {
        size_t operator()(const string &str)
        {

            size_t val = 0;
            for (auto ch : str)
            {
                val *= 131;
                val += ch;
            }
            return val;
        }
    };

    template <class Key, class Value>
    struct HashData
    {
        State _state = EMPTY;
        pair<Key, Value> _kv;
    };

    template <class Key, class Value, class Hash = HashFunc<Key>>
    class HashTable
    {
    public:
        HashData<Key, Value> *find(const Key &key)
        {
            if (_table.size() == 0)
                return nullptr;
            else
            {
                Hash hs;
                size_t hashi = hs(key) % _table.size();
                size_t start = hashi;
                while (_table[hashi]._state != EMPTY)
                {
                    if (_table[hashi]._state == EXIST && _table[hashi]._kv.first == key)
                        return &_table[hashi];
                    hashi++;
                    hashi %= _table.size();
                    if (hashi == start)
                        return nullptr;
                }
                return nullptr;
            }
        }
        bool insert(const pair<Key, Value> &kv)
        {

            if (find(kv.first))
                return false;
            else
            {
                // 扩容
                if (_table.size() * 0.7 == _size)
                {
                    size_t old = _table.size();
                    size_t newsize = (old == 0 ? 10 : old * 2);
                    vector<HashData<Key, Value>> newtable;
                    newtable.resize(newsize);
                    _table.swap(newtable);
                    for (auto &e : newtable)
                    {
                        if (e._state == EXIST)
                            insert(e._kv);
                    }
                }
                Hash hs;
                size_t hashi = hs(kv.first) % _table.size();
                while (_table[hashi]._state == EXIST)
                {
                    hashi++;
                    hashi %= _table.size();
                }
                _table[hashi]._kv = kv;
                _table[hashi]._state = EXIST;
                _size++;
                return true;
            }
        }
        bool erase(const Key &key)
        {
            HashData<Key, Value> *ret = find(key);
            if (ret == nullptr)
                return false;
            else
            {
                ret->_state = ERASE;
                _size--;
                return true;
            }
        }
        void Print()
        {
            for (size_t i = 0; i < _table.size(); i++)
            {
                if (_table[i]._state == EXIST)
                    cout << "(" << i << ")"
                         << "[" << _table[i]._kv.first << "]" << _table[i]._kv.second << endl;

                else
                    printf("[%d][***]\n");
            }
            cout << "------------------------------------------------" << endl;
        }

    private:
        vector<HashData<Key, Value>> _table;
        size_t _size = 0;
    };
};
