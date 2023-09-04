#pragma once

#include <string.h>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <stdbool.h>
using namespace std;

namespace Jeffrey
{
    template <class iterator, class Ref>
    class __reverse_iterator
    {
    public:
        typedef __reverse_iterator<iterator, Ref> Self;
        __reverse_iterator(const iterator &it)
            : _it(it)
        {
        }
        Self &operator++()
        {
            --_it;
            return *this;
        }
        Self &operator--()
        {
            ++_it;
            return *this;
        }
        Ref operator*()
        {
            iterator tmp = _it;
            --tmp;
            return *tmp;
        }
        bool operator==(const Self &rit)
        {
            return _it == rit._it;
        }
        bool operator!=(const Self &rit)
        {
            return _it != rit._it;
        }

    private:
        iterator _it;
    };

    class string
    {
    public:
        typedef char *iterator;
        typedef const char *const_iterator;
        typedef __reverse_iterator<iterator, char &> reverse_iterator;
        typedef __reverse_iterator<const_iterator, const char &> const_reverse_iterator;

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
        reverse_iterator rbegin()
        {
            return end();
        }
        const_reverse_iterator rbegin() const
        {
            return end();
        }
        reverse_iterator rend()
        {
            return begin();
        }
        const_reverse_iterator rend() const
        {
            return begin();
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
        string(const char *str = "")
        {
            assert(str);
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_size + 1];
            strcpy(_str, str);
        }
        string(size_t n, const char &ch)
        {
            _str = new char[n + 1];
            for (size_t i = 0; i < n; i++)
                _str[i] = ch;
            _size = _capacity = n;
            _str[_size] = '\0';
        }
        string(const string &str)
            : _str(nullptr), _size(0), _capacity(0)
        {
            string tmp(str._str);
            swap(tmp);
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        string &operator=(string str)
        {
            swap(str);
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
        string &append(const char *str)
        {
            assert(str);
            size_t len = strlen(str);
            if (_size + len > _capacity)
                reserve(_size + len);
            strcpy(_str + _size, str);
            _size += len;
            return *this;
        }
        string &append(const string &str)
        {
            return append(str._str);
        }
        string &append(size_t n, const char &ch)
        {
            for (size_t i = 0; i < n; i++)
                push_back(ch);
            return *this;
        }
        string &operator+=(const char *str)
        {
            return append(str);
        }
        string &operator+=(const char &ch)
        {
            push_back(ch);
            return *this;
        }
        string &operator+=(const string &str)
        {
            return append(str);
        }
        string &insert(size_t pos, const char *str)
        {
            assert(pos <= _size);
            size_t len = strlen(str);
            if (_size + len > _capacity)
                reserve(_size + len);
            memmove(_str + pos + len, _str + pos, _size - pos + 1);
            strncpy(_str + pos, str, len);
            _size += len;
            return *this;
        }
        string &insert(size_t pos, const string &str)
        {
            return insert(pos, str._str);
        }
        string &insert(size_t pos, size_t n, const char &ch)
        {
            string str(n, ch);
            return insert(pos, str);
        }
        string &erase(size_t pos, size_t len = npos)
        {
            if (len == npos || pos + len >= _size)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                memmove(_str + pos, _str + pos + len, _size - pos - len + 1);
                _size -= len;
            }
            return *this;
        }

        void clear()
        {
            _size = 0;
            _str[_size] = '\0';
        }

        size_t find(const char *str, size_t pos = 0) const
        {
            assert(str);
            assert(pos < _size);
            char *ret = strstr(_str + pos, str);
            if (ret)
                return ret - _str;
            else
                return npos;
        }
        size_t find(const string &str, size_t pos = 0) const
        {
            return find(str._str);
        }
        size_t find(const char &ch, size_t pos = 0) const
        {
            assert(pos < _size);
            for (size_t i = pos; i < _size; i++)
            {
                if (_str[i] == ch)
                    return i;
            }
            return npos;
        }
        string substr(size_t pos = 0, size_t len = npos) const
        {
            if (len == npos || pos + len >= _size)
                return string(_str + pos);
            else
            {
                string str;
                str.reserve(len);
                strncpy(str._str, _str + pos, len);
                str._size += len;
                return str;
            }
        }
        bool operator==(const string &str) const
        {
            return strcmp(_str, str._str) == 0;
        }
        bool operator>=(const string &str) const
        {
            return *this > str || *this == str;
        }
        bool operator<=(const string &str) const
        {
            return !(*this > str);
        }
        bool operator>(const string &str) const
        {
            return strcmp(_str, str._str) > 0;
        }
        bool operator<(const string &str) const
        {
            return !(*this >= str);
        }
        bool operator!=(const string &str) const
        {
            return !(*this == str);
        }

    private:
        char *_str;
        size_t _size;
        size_t _capacity;
        const static size_t npos = -1;
    };

    ostream &operator<<(ostream &out, const string &str)
    {
        out << str.c_str();
        return out;
    }
    istream &operator>>(istream &in, string &str)
    {
        char ch;
        while (1)
        {
            ch = in.get();
            if (ch != ' ' && ch != '\n')
                break;
        }
        char buf[33];
        size_t i = 0;
        while (ch != '\n')
        {
            buf[i++] = ch;
            ch = in.get();
            if (i == 32)
            {
                buf[i] = '\0';
                i = 0;
                str += buf;
            }
        }
        buf[i] = '\0';
        str += buf;
        return in;
    }

    void test1()
    {
        string s1 = "abcd";
        s1.append("efghijk");
        const string s2 = "cccccc";
        s1.append(s2);
        s1.push_back('a');
        cout << s1.append(5, '6').c_str() << endl;
        cout << s1.insert(2, "8888").c_str() << endl;
        cout << s1.insert(2, s2).c_str() << endl;
        cout << s1.insert(2, 3, '3').c_str() << endl;
        cout << s1.erase(3, 3).c_str() << endl;
        s1.clear();
        s1 += "abcd";
        s1 += s2;
        s1 += 'h';
        cout << s1.c_str() << endl;
        cout << s1.find(s2) << endl;
        string s3 = s1.substr(3, 2);
        cout << s3.c_str() << endl;
    }
    void test2()
    {
        string s = "abcdef";
        cout << s.substr(2, 2).c_str() << endl;
        s.resize(10, 'c');
        cout << s.c_str() << endl;
    }
    void test3()
    {
        string s1 = "abcd";
        string s2 = "1234";
        cout << s1 << s2 << endl;
    }
    void test4()
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        cout << s1 << endl;
        cout << s2 << endl;
    }
};