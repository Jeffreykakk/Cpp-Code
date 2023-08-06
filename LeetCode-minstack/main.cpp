#include <stack>
#include <iostream>
#include <windows.h>

using namespace std;

// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        _st.push(val);
        if (_min.empty() || val <= _min.top())
            _min.push(val);
    }

    void pop()
    {
        if (_st.top() == _min.top())
            _min.pop();
        _st.pop();
    }

    int top()
    {
        return _st.top();
    }

    int getMin()
    {
        return _min.top();
    }

private:
    stack<int> _st;
    stack<int> _min;
};

int main()
{
    MinStack st;
    st.push(5);
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    cout << st.getMin() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.getMin() << endl;
    system("pause");
    return 0;
}