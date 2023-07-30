#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

// 给你一个字符串 s ，根据下述规则反转字符串：
// 所有非英文字母保留在原有位置
// 所有英文字母（小写或大写）位置反转
// 返回反转后的 s

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !isalpha(s[begin]))
                begin++;
            while (begin < end && !isalpha(s[end]))
                end--;
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
        return s;
    }
};

int main()
{
    cout << Solution().reverseOnlyLetters("a-bC-dEf-ghIj") << endl;
    system("pause");
    return 0;
}