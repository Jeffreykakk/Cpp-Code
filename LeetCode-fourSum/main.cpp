#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

// 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target
// 请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]]
// 0 <= a, b, c, d < n
// a、b、c 和 d 互不相同
// nums[a] + nums[b] + nums[c] + nums[d] == target
// 若两个四元组元素一一对应，则认为两个四元组重复

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> vv;
        int end1 = nums.size() - 1;
        while (end1 >= 3)
        {
            int end2 = end1 - 1;
            while (end2 >= 2)
            {
                int left = 0, right = end2 - 1;
                while (left < right)
                {
                    long long target1 = (long long)target - nums[end1] - nums[end2];
                    if (nums[left] + nums[right] < target1)
                        left++;
                    else if (nums[left] + nums[right] > target1)
                        right--;
                    else
                    {
                        vv.push_back({nums[left], nums[right], nums[end2], nums[end1]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
                end2--;
                while (end2 >= 2 && nums[end2] == nums[end2 + 1])
                    end2--;
            }
            end1--;
            while (end1 >= 3 && nums[end1] == nums[end1 + 1])
                end1--;
        }
        return vv;
    }
};

int main()
{
    vector<int> v = {1, 0, -1, 0, -2, 2};
    auto ret = Solution().fourSum(v,0);
    for (auto &e1 : ret)
    {
        cout << "[";
        for (size_t i = 0; i < 4; i++)
        {
            if (i != 3)
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