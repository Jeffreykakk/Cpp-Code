#pragma once

#include <string.h>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <stdbool.h>
using namespace std;

namespace Jeffrey
{
    class string
    {
    public:
        typedef char *iterator;
        typedef const char *const_iterator;

        // 迭代器
        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }

        const_iterator begin() const
        {
            return _str;
        }

        const_iterator end() const
        {
            return _str + _size;
        }

        size_t size() const
        {
            return _size;
        }

        size_t capacity() const
        {
            return _capacity;
        }

        char &operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }

        const char &operator[](size_t pos) const
        {
            assert(pos < _size);
            return _str[pos];
        }

        const char *c_str() const
        {
            return _str;
        }

        // 交换
        void swap(string &s)
        {
            ::swap(_str, s._str);
            ::swap(_size, s._size);
            ::swap(_capacity, s._capacity);
        }

        // 默认成员函数
        string(const char *s = "")
        {
            assert(s);
            _size = strlen(s);
            _capacity = _size;
            _str = new char[_size + 1];
            strcpy(_str, s);
        }

        string(const string &s)
            : _str(nullptr), _size(0), _capacity(0)
        {
            string tmp(s._str);
            swap(tmp);
        }

        ~string()
        {
            delete[] _str;
            _size = _capacity = 0;
        }

        string &operator=(string s)
        {
            swap(s);
            return *this;
        }

        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char *tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
                _str[n] = '\0';
            }
        }

        void resize(size_t n, char ch = '\0')
        {
            if (n > _capacity)
                reserve(n);
            if (n > _size)
            {
                for (size_t i = _size; i < n; i++)
                    _str[i] = ch;
                _str[n] = '\0';
                _size = n;
            }
            else
            {
                _size = n;
                _str[_size] = '\0';
            }
        }

        void push_back(char ch)
        {
            if (_size == _capacity)
                reserve(_capacity == 0 ? 4 : _capacity * 2);
            _str[_size] = ch;
            _size++;
            _str[_size] = '\0';
        }
        bool empty() const
        {
            return _size == 0;
        }
        void append(const char *s)
        {
            assert(s);
            int len = strlen(s);
            if (_size + len > _capacity)
                reserve(_size + len);
            strncpy(_str + _size, s, len);
            _size += len;
            _str[_size] = '\0';
        }
        string &operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }
        string &operator+=(const char *s)
        {
            append(s);
            return *this;
        }
        string &insert(size_t pos, char ch)
        {
            assert(pos <= _size);
            if (_size == _capacity)
                reserve(_capacity == 0 ? 4 : _capacity * 2);
            int end = size() + 1;
            while (pos < end)
            {
                _str[end] = _str[end - 1];
                end--;
            }
            _str[pos] = ch;
            _size++;
            return *this;
        }
        string &insert(size_t pos, const char *s)
        {
            assert(s);
            assert(pos <= _size);
            int len = strlen(s);
            if (_size + len > _capacity)
                reserve(_size + len);
            memmove(_str + pos + len, _str + pos, sizeof(char) * (_size - pos + 1));
            strncpy(_str + pos, s, len);
            _size += len;
            return *this;
        }
        string &erase(size_t pos, size_t len = npos)
        {
            if (pos + len >= _size || len == npos)
            {
                _str[pos] = '\0';
                _size -= len;
            }
            else
            {
                memmove(_str + pos, _str + pos + len, sizeof(char) * (_size - pos - len + 1));
                _size -= len;
            }
            return *this;
        }

        void clear()
        {
            _size = 0;
            _str[_size] = '\0';
        }

        size_t find(char ch, size_t pos = 0) const
        {
            assert(pos < _size);
            for (size_t i = pos; i < _size; i++)
            {
                if (_str[i] == ch)
                    return i;
            }
            return npos;
        }
        size_t find(const char *s, size_t pos = 0) const
        {
            assert(pos < _size);
            assert(s);
            char *ret = strstr(_str + pos, s);
            if (ret == nullptr)
                return npos;
            else
                return ret - _str;
            return npos;
        }
        string substr(size_t pos = 0, size_t len = npos) const
        {
            string sub;
            if (len == npos || pos + len >= _size)
            {
                sub.reserve(_size - pos);
                strcpy(sub._str, _str + pos);
                sub._size = _size - pos;
            }
            else
            {
                sub.reserve(len);
                strncpy(sub._str, _str + pos, len);
            }
            return sub;
        }
        bool operator==(const string &s) const
        {
            return strcmp(_str, s._str) == 0;
        }
        bool operator>=(const string &s) const
        {
            return *this > s || *this == s;
        }
        bool operator<=(const string &s) const
        {
            return !(*this > s);
        }
        bool operator>(const string &s) const
        {
            return strcmp(_str, s._str) > 0;
        }
        bool operator<(const string &s) const
        {
            return !(*this >= s);
        }
        bool operator!=(const string &s) const
        {
            return !(*this == s);
        }

    private:
        char *_str;
        size_t _size;
        size_t _capacity;
        const static size_t npos;
    };
    const size_t string::npos = -1;

    ostream &operator<<(ostream &out, const string &s)
    {
        for (auto &e : s)
            cout << e;
        return out;
    }
    istream &operator>>(istream &in, string &s)
    {
        char ch;
        while (1)
        {
            ch = in.get();
            if (ch != ' ' && ch != '\n')
                break;
        }
        char buf[16];
        size_t i = 0;
        while (ch != '\n')
        {
            buf[i++] = ch;
            if (i == 15)
            {
                buf[i] = '\0';
                i = 0;
                s += buf;
            }
            ch = in.get();
        }
        buf[i] = '\0';
        s += buf;

        return in;
    }

    void test_string()
    {
        string s1;
        string s2;
        cin >> s1;
        cin >> s2;
        cout << s1 << endl;
        cout << s2 << endl;
    }
};