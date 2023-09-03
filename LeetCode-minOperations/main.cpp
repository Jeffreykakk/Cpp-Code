#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

// 给你一个整数数组 nums 和一个整数 x
// 每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值
// 请注意，需要 修改数组以供接下来的操作使用。
// 如果可以将 x 恰好 减到 0 ，返回最小操作数 ；否则，返回 - 1

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int all = 0, sz = nums.size();
        for (size_t i = 0; i < sz; i++)
            all += nums[i];
        int target = all - x;
        if (target < 0)
            return -1;
        int len = -1, left = 0, right = 0, sum = 0;
        while (right < sz)
        {
            sum += nums[right];
            while (sum > target)
                sum -= nums[left++];
            if (sum == target)
                len = max(len, right - left + 1);
            right++;
        }
        if (len == -1)
            return -1;
        else
            return sz - len;
    }
};

int main()
{
    vector<int> v = {3, 2, 20, 1, 1, 3};
    cout << Solution().minOperations(v, 10) << endl;
    system("pause");
    return 0;
}