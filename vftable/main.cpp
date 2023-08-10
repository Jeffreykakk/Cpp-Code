#include <iostream>
#include <windows.h>
using namespace std;

// 打印虚函数表

class Base
{
public:
    virtual void func1() { cout << "Base::func1" << endl; }
    virtual void func2() { cout << "Base::func2" << endl; }

private:
    int a;
};
class Derive : public Base
{
public:
    virtual void func1() { cout << "Derive::func1" << endl; }
    virtual void func3() { cout << "Derive::func3" << endl; }
    virtual void func4() { cout << "Derive::func4" << endl; }

private:
    int b;
};

typedef void (*VFPTR)();

void PrintVTable(VFPTR vTable[],int count)
{
    // 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
    cout << " 虚表地址>" << vTable << endl;
    for (int i = 0; i<count; ++i)
    {
        printf(" 第%d个虚函数地址 : 0X%x -> ", i+1, vTable[i]);
        VFPTR f = vTable[i];
        f();
    }
    cout << endl;
}

int main()
{
    Base b;
    Derive d;
    VFPTR *vTableb1 = (VFPTR *)(*((long long *)&b));
    PrintVTable(vTableb1,2);
    VFPTR *vTabled2 = (VFPTR *)(*(long long *)&d);
    PrintVTable(vTabled2,4);
    system("pause");
    return 0;
}