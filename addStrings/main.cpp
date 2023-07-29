#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
using namespace std;

// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int flag = 0;
        string num;
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = (end1 >= 0 ? num1[end1] - '0' : 0);
            int val2 = (end2 >= 0 ? num2[end2] - '0' : 0);
            int add = val1 + val2 + flag;
            flag = (add > 9 ? 1 : 0);
            num.push_back((add % 10) + '0');
            end1--;
            end2--;
        }
        if (flag)
            num.push_back('1');
        reverse(num.begin(), num.end());
        return num;
    }
};

int main()
{
    cout << Solution().addStrings("11", "123") << endl;
    system("pause");
    return 0;
}