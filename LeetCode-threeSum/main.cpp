#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k
// 同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
// 你返回所有和为 0 且不重复的三元组

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> vv;
        sort(nums.begin(), nums.end());
        int end = nums.size() - 1;
        while (end >= 2 && nums[end] >= 0)
        {
            int left = 0, right = end - 1, target = -nums[end];
            while (left < right)
            {
                if (nums[left] + nums[right] < target)
                    left++;
                else if (nums[left] + nums[right] > target)
                    right--;
                else
                {
                    vv.push_back({nums[left], nums[right], nums[end]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
            end--;
            while (end >= 2 && nums[end] == nums[end + 1])
                end--;
        }
        return vv;
    }
};

int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    auto ret = Solution().threeSum(v);
    for (auto &e1 : ret)
    {
        cout << "[";
        for (size_t i = 0; i < 3; i++)
        {
            if (i != 2)
                cout << e1[i] << ",";
            else
                cout << e1[i];
        }
        cout << "]";
        cout << endl;
    }
    system("pause");
    return 0;
}