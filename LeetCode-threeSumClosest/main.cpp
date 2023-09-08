#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 给你一个长度为 n 的整数数组 nums 和 一个目标值 target
// 请你从 nums 中选出三个整数，使它们的和与 target 最接近
// 返回这三个数的和
// 假定每组输入只存在恰好一个解

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int end = nums.size() - 1, ret = 0, gap = INT_MAX;
        while (end >= 2)
        {
            int left = 0, right = end - 1;
            while (left < right)
            {
                int add = nums[left] + nums[right] + nums[end];
                if (add == target)
                    return add;
                if (abs(add - target) < gap)
                {
                    ret = add;
                    gap = abs(add - target);
                }
                if (add < target)
                    left++;
                else
                    right--;
            }
            end--;
        }
        return ret;
    }
};

int main()
{
    vector<int> v = {-1, 2, 1, -4};
    cout << Solution().threeSumClosest(v, -1) << endl;
    system("pause");
    return 0;
}