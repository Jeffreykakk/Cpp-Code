#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

// 如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样
// 则可以认为该短语是一个回文串
// 给你一个字符串 s ，如果它是 回文串 ，返回 true ；否则，返回 false

class Solution
{
public:
    bool is(char c)
    {
        return isdigit(c) || islower(c);
    }
    bool isPalindrome(string s)
    {
        for (auto &e : s)
        {
            if (isupper(e))
                e += 32;
        }
        cout << s << endl;
        int begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !is(s[begin]))
                begin++;
            while (begin < end && !is(s[end]))
                end--;
            if (s[begin++] != s[end--])
                return false;
        }
        return true;
    }
};

int main()
{
    string s("A man, a plan, a canal: Panama");
    cout << Solution().isPalindrome(s) << endl;
    system("pause");
    return 0;
}