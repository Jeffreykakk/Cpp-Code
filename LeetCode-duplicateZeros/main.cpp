#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

// 给你一个长度固定的整数数组 arr ，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移
// 注意：请不要在超过该数组长度的位置写入元素
// 请对输入的数组就地进行上述修改，不要从函数返回任何东西

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int cur = -1, dst = -1, sz = arr.size();
        while (1)
        {
            if (arr[++cur] == 0)
                dst += 2;
            else
                dst++;
            if (dst >= sz - 1)
                break;
        }
        if (dst == sz)
        {
            arr[sz - 1] = 0;
            dst -= 2;
            cur--;
        }
        while (cur >= 0)
        {
            if (arr[cur] == 0)
            {
                arr[dst--] = arr[cur];
                arr[dst--] = arr[cur];
            }
            else
                arr[dst--] = arr[cur];
            cur--;
        }
    }
};

int main()
{
    vector<int> v{1, 0, 2, 3, 0, 4, 5, 0};
    Solution().duplicateZeros(v);
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
    system("pause");
    return 0;
}