#include <vector>
#include <queue>
#include <iostream>
#include <windows.h>

using namespace std;

// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素
// 要求时间复杂度为 O(n)

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> pq;
        for(auto& e:nums)
        pq.push(e);
        while(--k)
        pq.pop();
        return pq.top();
    }
};

int main()
{
    vector<int> v{3,2,3,1,2,4,5,5,6};
    cout << Solution().findKthLargest(v,4) << endl;
    system("pause");
    return 0;
}