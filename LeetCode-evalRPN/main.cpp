#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

// 给你一个字符串数组 tokens ，表示一个根据逆波兰表示法表示的算术表达式
// 请你计算该表达式。返回一个表示表达式值的整数。

class Solution
{
private:
    stack<int> _st;

public:
    int evalRPN(vector<string> &tokens)
    {
        for (auto &e : tokens)
        {
            if (e == "+" || e == "-" || e == "*" || e == "/")
            {
                int right = _st.top();
                _st.pop();
                int left = _st.top();
                _st.pop();
                switch (e[0])
                {
                case '+':
                    _st.push(left + right);
                    break;
                case '-':
                    _st.push(left - right);
                    break;
                case '*':
                    _st.push(left * right);
                    break;
                case '/':
                    _st.push(left / right);
                    break;
                }
            }
            else
                _st.push(stoi(e));
        }
        return _st.top();
    }
};

int main()
{
    vector<string> v{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << Solution().evalRPN(v) << endl;
    system("pause");
    return 0;
}