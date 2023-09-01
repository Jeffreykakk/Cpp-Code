#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

// 输入一个递增排序的数组和一个数字 s ，在数组中查找两个数，使得它们的和正好是 s
// 如果有多对数字的和等于 s ，则输出任意一对即可
// 返回和为 s 的两个数

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        size_t left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] < target)
                left++;
            else if (nums[left] + nums[right] > target)
                right--;
            else
                break;
        }
        vector<int> v;
        v.push_back(nums[left]);
        v.push_back(nums[right]);
        return v;
    }
};

int main()
{
    vector<int> v = {2, 7, 11, 15};
    vector<int> ret = Solution().twoSum(v, 9);
    for (auto &e : ret)
        cout << e << " ";
    cout << endl;
    system("pause");
    return 0;
}