#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

// 给定一个单词列表 words 和一个整数 k ，返回前 k 个出现次数最多的单词
// 返回的答案应该按单词出现频率由高到低排序
// 如果不同的单词有相同出现频率， 按字典顺序排序

struct comp
{
    bool operator()(const pair<string, int> &kv1, const pair<string, int> &kv2) const
    {
        if (kv1.second < kv2.second)
            return true;
        else if (kv1.second == kv2.second && kv1.first > kv2.first)
            return true;
        else
            return false;
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
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> maxheap(m.begin(), m.end());
        vector<string> v;
        while (k--)
        {
            v.push_back(maxheap.top().first);
            maxheap.pop();
        }
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