#include <iostream>
#include <windows.h>
#include <string>
#include <set>

using namespace std;

// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> count;
        for (size_t i = 0; i < s.size();i++)
        {
            bool ret = count.insert(s[i]).second;
            if (ret == false)
                break;
        }
        size_t win= count.size();
        count.clear();
        for (size_t i = 1; i + win < s.size(); i++)
        {
            size_t j = 0;
            for (j = i; j < s.size(); j++)
            {
                bool ret = count.insert(s[j]).second;
                if (ret == false)
                    break;
                if (j - i >= win)
                {
                    win++;
                }
            }
            count.clear();
        }
        return win;
    }
};

int main()
{
    string s = "pwwkew";
    cout <<Solution().lengthOfLongestSubstring(s)<<endl;
    system("pause");
    return 0;
}