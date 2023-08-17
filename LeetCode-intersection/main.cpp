#include <iostream>
#include <windows.h>
#include <vector>
#include <set>

using namespace std;

// 给定两个数组 nums1 和 nums2 ，返回它们的交集
// 输出结果中的每个元素一定是唯一的，我们可以 不考虑输出结果的顺序



class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> v;
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        auto it1 = s1.begin();
        auto it2 = s2.begin();
        while (it1 != s1.end() && it2 != s2.end())
        {
            if (*it1 < *it2)
                it1++;
            else if (*it1 > *it2)
                it2++;
            else
            {
                v.push_back(*it1);
                it1++;
                it2++;
            }
        }
        return v;
    }
};

int main()
{
    vector<int> v1{1, 2, 2, 1};
    vector<int> v2{2, 2};
    vector<int> v = Solution().intersection(v1, v2);
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
    system("pause");
    return 0;
}