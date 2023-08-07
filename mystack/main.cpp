#include "mystack.h"
#include <stack>

void test_stack()
{
    stack<int> st1;
    stack<int> st2;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);
    st2.push(3);
    st2.push(5);
    st2.push(8);
    st1.swap(st2);
    while (!st1.empty())
    {
        cout << st1.top() << ' ';
        st1.pop();
    }
    cout << endl;
    while (!st2.empty())
    {
        cout << st2.top() << ' ';
        st2.pop();
    }
    cout << endl;
}

int main()
{
    Jeffrey::test_stack();
    cout << "--------------------" << endl;
    ::test_stack();
    system("pause");
    return 0;
}