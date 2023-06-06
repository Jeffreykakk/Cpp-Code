#pragma once

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <windows.h>

typedef int StackDatatype;
using namespace std;

namespace Jeffrey
{
    class stack
    {
    public:
        stack(int capacity=4)
        {
            _data=(StackDatatype*)malloc(sizeof(StackDatatype)*capacity);
            _capacity=capacity;
            _top=0;
        }
        stack(const stack& st)
        {
            _data=(StackDatatype*)malloc(sizeof(StackDatatype)*st._capacity);
            memcpy(_data,st._data,sizeof(StackDatatype)*st._capacity);
            _top=st._top;
            _capacity=st._capacity;
        }
        ~stack()
        {
            free(_data);
        }
        bool Empty();
        void Push(StackDatatype x);
        void Pop();
        StackDatatype Top();
        int Size();
        void Print();
    private:
        StackDatatype* _data;
        int _top;
        int _capacity;
    };
};









