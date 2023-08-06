#include <stack>
#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

// 给定 pushed 和 popped 两个序列，每个序列中的值都不重复
// 只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true
// 否则，返回 false

class Solution
{
private:
    stack<int> _st;

public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int i = 0;
        for (auto &e : pushed)
        {
            _st.push(e);
            while (!_st.empty() && _st.top() == popped[i])
            {
                i++;
                _st.pop();
            }
        }
        return _st.empty();
    }
};

int main()
{
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{4, 5, 3, 2, 1};
    cout << Solution().validateStackSequences(v1, v2)<<endl;
    system("pause");
    return 0;
}