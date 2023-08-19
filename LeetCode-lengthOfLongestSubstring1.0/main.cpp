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
        int lenmax=0;
        for(size_t i=0;i<s.size();i++)
        {
            set<char> count;
            for(size_t j=i;j<s.size();j++)
            {
                bool ret=count.insert(s[j]).second;
                if(ret==false)
                break;
            }
            size_t len=count.size();
            if(len>lenmax)
            lenmax=len;
        }
        return lenmax;
    }
};

int main()
{
    string s="abcabcbb";
    cout <<Solution().lengthOfLongestSubstring(s)<<endl;
    system("pause");
    return 0;
}