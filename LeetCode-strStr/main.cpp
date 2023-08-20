#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标
// 如果 needle 不是 haystack 的一部分，则返回 -1

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        size_t str_len = haystack.size();
        size_t sub_len = needle.size();
        for (size_t i = 0; i + sub_len <= str_len; i++)
        {
            size_t j = 0, k = 0;
            for (j = i, k = 0; j - i < sub_len; j++, k++)
            {
                if (haystack[j] != needle[k])
                    break;
            }
            if (j - i == sub_len)
                return i;
        }
        return -1;
    }
};

int main()
{
    string s1 = "sadbutsad";
    string s2 = "adbut";
    cout << Solution().strStr(s1, s2) << endl;
    system("pause");
    return 0;
}