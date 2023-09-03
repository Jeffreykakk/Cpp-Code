#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

// 给定一个二进制数组 nums 和一个整数 k
// 如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0, right = 0, count = 0, sz = nums.size();
        int len = 0;
        while (right < sz)
        {
            if (nums[right] == 0)
                count++;
            if (count <= k)
                len = max(len, right - left + 1);
            while (count > k)
            {
                if (nums[left++] == 0)
                    count--;
            }
            right++;
        }
        return len;
    }
};

int main()
{
    vector<int> v = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << Solution().longestOnes(v, 2) << endl;
    system("pause");
    return 0;
}