#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 给定一个单词列表 words 和一个整数 k ，返回前 k 个出现次数最多的单词
// 返回的答案应该按单词出现频率由高到低排序
// 如果不同的单词有相同出现频率， 按字典顺序排序

struct Greater
{
    bool operator()(const pair<string, int> &kv1, const pair<string, int> &kv2) const
    {
        return kv1.second > kv2.second;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> m;
        for (auto &e : words)
            m[e]++;
        vector<pair<string, int>> vsort(m.begin(), m.end());
        stable_sort(vsort.begin(), vsort.end(), Greater());
        vector<string> v;
        for (size_t i = 0; i < k; i++)
            v.push_back(vsort[i].first);
        return v;
    }
};

int main()
{
    vector<string> vstr = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> v = Solution().topKFrequent(vstr, 2);
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
    system("pause");
    return 0;
}