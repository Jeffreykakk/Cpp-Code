#include <iostream>
#include <windows.h>
#include <vector>
#include <bitset>

using namespace std;

// 给定两个数组 nums1 和 nums2 ，返回它们的交集
// 输出结果中的每个元素一定是唯一的，我们可以 不考虑输出结果的顺序

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> v;
        bitset<1001> bs1;
        bitset<1001> bs2;
        for (auto e : nums1)
            bs1.set(e);
        for (auto e : nums2)
            bs2.set(e);
        for (size_t i = 0; i < 1001; i++)
        {
            if (bs1.test(i) == 1 && bs2.test(i) == 1)
                v.push_back(i);
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