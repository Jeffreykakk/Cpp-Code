#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

// 你正在探访一家农场，农场从左到右种植了一排果树
// 这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果种类

// 你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：

// 你只有两个篮子，并且每个篮子只能装单一类型的水果。每个篮子能够装的水果总量没有限制
// 你可以选择任意一棵树开始采摘，你必须从每棵树（包括开始采摘的树）上恰好摘一个水果
// 采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘
// 一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
// 给你一个整数数组 fruits ，返回你可以收集的水果的最大数目

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        // 找最长子数组，使数组内部不同数的个数为 2
        int hash[100000] = {0};
        int left = 0, right = 0, kinds = 0, ret = 0, sz = fruits.size();
        while (right < sz)
        {
            if (hash[fruits[right]]++ == 0)
                kinds++;
            while (kinds > 2)
            {
                if (--hash[fruits[left++]] == 0)
                    kinds--;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 2, 2};
    cout << Solution().totalFruit(v) << endl;
    system("pause");
    return 0;
}