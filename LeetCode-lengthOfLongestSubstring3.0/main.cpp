#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int hash[128] = {0};
        size_t left = 0, right = 0, sz = s.size();
        size_t ret = 0;
        while (right < sz)
        {
            hash[s[right]]++;
            while (hash[s[right]] > 1)
                hash[s[left++]]--;
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};

int main()
{
    string s = "pwwkew";
    cout <<Solution().lengthOfLongestSubstring(s)<<endl;
    system("pause");
    return 0;
}