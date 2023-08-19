#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

// 给定一个含有 n 个正整数的数组和一个正整数 target 
// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组[numsl, numsl + 1, ..., numsr - 1, numsr] 
// 并返回其长度。如果不存在符合条件的子数组，返回 0

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        size_t left = 0, right = 0, sz = nums.size();
        size_t ret = -1, sum = 0;
        while (right < sz)
        {
            sum += nums[right];
            while (sum >= target)
            {
                ret = min(ret, right - left + 1);
                sum -= nums[left++];
            }
            right++;
        }
        if (ret == -1)
            return 0;
        else
            return ret;
    }
};

int main()
{
    vector<int> v = {2, 3, 1, 2, 4, 3};
    cout << Solution().minSubArrayLen(7,v) << endl;
    system("pause");
    return 0;
}