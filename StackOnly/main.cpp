#include <iostream>

//设计一个只能在栈上创建的类

class StackOnly
{
public:
    static StackOnly CreateObj(int x=0,int y=0)
    {
        StackOnly so(x, y);
        return so;
    }
private:
    StackOnly(int x,int y)
    :_x(x),
    _y(y)
    {
    }
    int _x;
    int _y;
};

int main()
{
    StackOnly so=StackOnly::CreateObj(1,1);
    return 0;
}