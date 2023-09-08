#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

// 给你一个字符串 s，找到 s 中最长的回文子串
// 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串

class Solution
{
public:
    bool isPalindrome(string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        int len = 0, i = 0, sz = s.size();
        for (int left = 0; left < sz; left++)
        {
            for (int right = 0; right < sz; right++)
            {
                if (right - left + 1 > len && isPalindrome(s, left, right))
                {
                    len = right - left + 1;
                    i = left;
                }
            }
        }
        return s.substr(i, len);
    }
};

int main()
{

    string s = Solution().longestPalindrome("babad");
    cout << s << endl;
    system("pause");
    return 0;
}