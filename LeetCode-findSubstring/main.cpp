#include <iostream>
#include <windows.h>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// 给定一个字符串 s 和一个字符串数组 words ， words 中所有字符串长度相同
// s 中的串联子串是指一个包含 words 中所有字符串以任意顺序排列连接起来的子串
// 返回所有串联子串在 s 中的开始索引，你可以以任意顺序返回答案

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int len = words[0].size();
        unordered_map<string, int> countmap1;
        for (auto &str : words)
            countmap1[str]++;
        // 执行滑动窗口的趟数
        vector<int> ret;
        for (int i = 0; i < len; i++)
        {
            int left = i, right = i, kinds = 0, sz = s.size(), count = words.size();
            unordered_map<string, int> countmap2;
            while (right + len <= sz)
            {
                string in = s.substr(right, len);
                ++countmap2[in];
                if (countmap1.count(in) && countmap2[in] <= countmap1[in])
                    kinds++;
                if (((right - left) / len + 1) > count)
                {
                    string out = s.substr(left, len);
                    if (countmap1.count(out) && countmap2[out] <= countmap1[out])
                        kinds--;
                    --countmap2[out];
                    left += len;
                }
                if (kinds == count)
                    ret.push_back(left);
                right += len;
            }
        }
        return ret;
    }
};
int main()
{
    vector<string> words = {"bar", "foo", "the"};
    vector<int> ret = Solution().findSubstring("barfoofoobarthefoobarman", words);
    for (auto e : ret)
        cout << e << " ";
    cout << endl;
    system("pause");
    return 0;
}