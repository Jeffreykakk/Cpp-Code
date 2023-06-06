#include "Stack.h"

using namespace Jeffrey;


bool stack::Empty()          //检查栈是否为空
{
    return _top==0;
}

void stack::Push(StackDatatype x)           //向栈中存放数据
{
    if(_capacity==_top)       //考虑扩容
    {
        int newcapacity=_capacity==0?4:_capacity*2;
        StackDatatype* tmp=(StackDatatype*)realloc(_data,newcapacity*sizeof(StackDatatype));
        if(tmp==NULL)
        {
            printf("扩容失败\n");
            exit(-1);
        }
        _capacity=newcapacity;
        _data=tmp;
    }
    _data[_top]=x;
    _top++;
}

void stack::Pop()            //删除栈中的数据
{
    assert(!stack::Empty());        //栈不为空
    _top--;
}

StackDatatype stack::Top()   //取出栈顶的数据
{
    assert(!stack::Empty());        //栈不为空
    return _data[_top-1];
}

int stack::Size()            //栈中存放数据的个数
{
    return _top;
}

void stack::Print()
{
    stack copy=*this;
    while(!copy.Empty())
    {
        cout << copy.Top() << endl;
        copy.Pop();
    }
}