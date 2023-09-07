#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

// 给定两个字符串 s 和 p，找到 s 中所有 p 的异位词的子串，返回这些子串的起始索引
// 不考虑答案输出的顺序
// 异位词指由相同字母重排列形成的字符串（包括相同的字符串）

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int hash1[26] = {0};
        int hash2[26] = {0};
        for (auto ch : p)
            hash1[ch - 'a']++;
        vector<int> ret;
        int len = p.size();
        int left = 0, right = 0, sz = s.size(), count = 0;
        while (right < sz)
        {
            char in = s[right];
            if (++hash2[in - 'a'] <= hash1[in - 'a'])
                count++;
            if (right - left + 1 > len)
            {
                char out = s[left++];
                if (hash2[out - 'a']-- <= hash1[out - 'a'])
                    count--;
            }
            if (count == len)
                ret.push_back(left);
            right++;
        }
        return ret;
    }
};

int main()
{

    vector<int> ret = Solution().findAnagrams("cbaebabacd", "abc");
    for(auto e : ret)
        cout << e << " ";
    cout << endl;
    system("pause");
    return 0;
}