#pragma once

namespace Jeffrey
{
    template <class iterator, class Ref, class Ptr>
    struct __reverse_iterator
    {
        iterator _cur;

        typedef __reverse_iterator<iterator, Ref, Ptr> _reverse_iterator;
        __reverse_iterator(const iterator &it)
            : _cur(it)
        {
        }
        _reverse_iterator &operator++()
        {
            --_cur;
            return *this;
        }
        _reverse_iterator operator++(int)
        {
            _reverse_iterator tmp = *this;
            --_cur;
            return *this;
        }
        _reverse_iterator &operator--()
        {
            ++_cur;
            return *this;
        }
        _reverse_iterator operator--(int)
        {
            _reverse_iterator tmp = *this;
            ++_cur;
            return *this;
        }
        Ref operator*() const
        {
            iterator tmp = _cur;
            --tmp;
            return *tmp;
        }
        Ptr operator->() const
        {
            iterator tmp = _cur;
            --tmp;
            return &(*tmp);
        }
        bool operator==(const _reverse_iterator &rit) const
        {
            return _cur == rit._cur;
        }
        bool operator!=(const _reverse_iterator &rit) const
        {
            return !(operator==(rit));
        }
    };
};