#include "Stack.h"

using namespace Jeffrey;

void test()
{
    stack st1;
    st1.Push(1);
    st1.Push(2);
    st1.Push(3);
    st1.Push(4);
    st1.Print();
}

int main()
{
    test();
    system("pause");
    return 0;
}