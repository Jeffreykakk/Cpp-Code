#include <iostream>
#include <vector>
#include <windows.h>
#include <unordered_map>
using namespace std;

// 给定一个整数数组 nums 和一个整数目标值 target，
// 请你在该数组中找出 和为目标值 target  的那两个整数
// 并返回它们的数组下标

// hashmap 解法
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        for (size_t i = 0; i < nums.size(); i++)
        {
            auto it = m.find(target - nums[i]);
            if (it == m.end())
                m[nums[i]] = i;
            else
                return {it->second, (int)i};
        }
        return {-1, -1};
    }
};

int main()
{
    vector<int> v = {3, 2, 4};
    vector<int> ret = Solution().twoSum(v, 6);
    for (auto &e : ret)
        cout << e << " ";
    cout << endl;
    system("pause");
    return 0;
}