#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <stdbool.h>
#include <list>
using namespace std;

namespace Jeffrey
{

    template <class T>
    class vector
    {
    public:
        typedef T *iterator;
        typedef const T *const_iterator;
        iterator begin()
        {
            return _start;
        }
        const_iterator begin() const
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
        const_iterator end() const
        {
            return _finish;
        }
        void swap(vector<T> &v)
        {
            ::swap(_start, v._start);
            ::swap(_finish, v._finish);
            ::swap(_end_of_storage, v._end_of_storage);
        }
        vector()
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
        }
        vector(const vector<T> &val)
        {
            int sz = val.size();
            _start = new T[sz];
            _finish = _start + sz;
            _end_of_storage = _start + sz;
            for (size_t i = 0; i < sz; i++)
                _start[i] = val._start[i];
        }
        vector<T> &operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }
        vector(int n, const T &val = T())
        {
            _start = new T[n];
            _finish = _start + n;
            _end_of_storage = _start + n;
            for (size_t i = 0; i < n; i++)
                _start[i] = val;
        }
        template <class InputIterator>
        vector(InputIterator first, InputIterator last)
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }
        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }
        size_t capacity() const
        {
            return _end_of_storage - _start;
        }
        size_t size() const
        {
            return _finish - _start;
        }
        bool empty()
        {
            return _start == _finish;
        }
        T &operator[](size_t pos)
        {
            assert(_start + pos < _finish);
            return _start[pos];
        }
        const T &operator[](size_t pos) const
        {
            assert(_start + pos < _finish);
            return _start[pos];
        }
        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t sz = size();
                T *tmp = new T[n];
                for (size_t i = 0; i < sz; i++)
                    tmp[i] = _start[i];
                delete[] _start;
                _start = tmp;
                _finish = _start + sz;
                _end_of_storage = _start + n;
            }
        }
        void resize(size_t n, const T &val = T())
        {
            if (n > capacity())
                reserve(n);
            if (n > size())
            {
                for (size_t i = size(); i < n; i++)
                    _start[i] = val;
                _finish = _start + n;
            }
            else
                _finish = _start + n;
        }
        void push_back(const T &x)
        {
            if (_start + size() == _end_of_storage)
                reserve(_start == nullptr ? 4 : capacity() * 2);
            *_finish = x;
            _finish++;
        }
        void pop_back()
        {
            assert(_finish > _start);
            _finish--;
        }
        iterator insert(iterator pos, const T &x)
        {
            assert(pos >= _start && pos <= _finish);
            size_t len = pos - _start;
            if (_start + size() == _end_of_storage)
            {
                reserve(_start == nullptr ? 4 : capacity() * 2);
                pos = _start + len;
            }
            T *end = _finish;
            while (end > pos)
            {
                *end = *(end - 1);
                end--;
            }
            *pos = x;
            _finish++;
            return pos;
        }
        iterator erase(iterator pos)
        {
            assert(pos >= _start && pos < _finish);
            memmove(pos, pos + 1, sizeof(T) * (_finish - pos - 1));
            _finish--;
            return pos;
        }
        T &front()
        {
            assert(!empty());
            return *_start;
        }
        T &back()
        {
            assert(!empty());
            return *(_finish - 1);
        }

    private:
        T *_start;
        T *_finish;
        T *_end_of_storage;
    };
    void test_vector1()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        vector<int> v2;
        for (size_t i = 0; i < v1.size(); i++)
            cout << v1[i] << ' ';
        cout << endl;
        v2 = v1;
        for (size_t i = 0; i < v2.size(); i++)
            cout << v2[i] << ' ';
        cout << endl;
    }

    void test_vector2()
    {
        
        vector<vector<int>> v(5);
        for (auto &e : v)
            cout << e.capacity() << ' ';
        cout << endl;
    }
    void test_vector3()
    {
        list<int> l;
        l.push_back(5);
        l.push_back(6);
        l.push_back(7);
        l.push_back(8);
        l.push_back(9);
        l.push_back(10);
        vector<int> v(l.begin(), l.end());
        for (auto &e : v)
            cout << e << ' ';
        cout << endl;
    }
    
    class Solution
    {
    public:
        vector<vector<int>> generate(int numRows)
        {
            vector<vector<int>> vv;
            vv.resize(numRows);
            
            for (size_t i = 0; i < vv.size(); ++i)
            {
                vv[i].resize(i + 1, 0);
                vv[i].front() = vv[i].back() = 1;
            }

            for (size_t i = 0; i < vv.size(); ++i)
            {
                for (size_t j = 0; j < vv[i].size(); ++j)
                {
                    if (vv[i][j] == 0)
                    {
                        vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
                    }
                }
            }

            for (size_t i = 0; i < vv.size(); ++i)
            {
                for (size_t j = 0; j < vv[i].size(); ++j)
                {
                    cout << vv[i][j] << " ";
                }
                cout << endl;
            }
            return vv;
        }
    };
    void test_vector4()
    {
        vector<vector<int>> ret = Solution().generate(5);
    }
};