#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

// 编写一个算法来判断一个数 n 是不是快乐数

// 「快乐数」 定义为：

// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环但始终变不到 1
// 如果这个过程 结果为 1，那么这个数就是快乐数。
// 如果 n 是 快乐数 就返回 true ；不是，则返回 false

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        int end = nums.size() - 1;
        while (end >= 2)
        {
            int left = 0, right = end - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[end])
                {
                    count += (right - left);
                    right--;
                }
                else
                    left++;
            }
            end--;
        }
        return count;
    }
};

int main()
{
    vector<int> v = {2, 2, 3, 4};
    cout << Solution().triangleNumber(v) << endl;
    system("pause");
    return 0;
}