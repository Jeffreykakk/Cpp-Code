#pragma once

#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

namespace Jeffrey
{
    template <size_t N>
    class bitset
    {
    public:
        bitset()
        {
            _bt = new char[N / 8 + 1];
            memset(_bt, 0, N / 8 + 1);
        }
        ~bitset()
        {
            delete[] _bt;
            _bt = nullptr;
        }
        // 1000 0000
        void set(size_t n)
        {
            size_t i = n / 8;
            size_t j = n % 8;
            _bt[i] |= (1 << j);
        }
        void reset(size_t n)
        {
            size_t i = n / 8;
            size_t j = n % 8;
            _bt[i] &= ~(1 << j);
        }
        bool test(size_t n)
        {
            size_t i = n / 8;
            size_t j = n % 8;
            return (_bt[i] >> j) & 1;
        }

    private:
        char *_bt;
    };

    void test1()
    {
        bitset<0xffffffff> bt;
        bt.set(4);
        cout << bt.test(4) << endl;
    }
    void test2()
    {
        bitset<1000> bt;
        int arr1[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int arr2[]{0, 1, 2, 4, 5, 6, 7, 8, 10};
        for (auto &e : arr1)
            cout << e << " ";
        cout << endl;
        for (auto &e : arr2)
            bt.set(e);
        for (auto &e : arr1)
            cout << bt.test(e) << " ";
        cout << endl;
    }
};
