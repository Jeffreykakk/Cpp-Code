#include <vector>
#include <windows.h>

// 给你一个整数数组 nums ，其中元素已经按升序排列，请你将其转换为一棵高度平衡二叉搜索树

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    TreeNode *_createTree(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = _createTree(nums, left, mid - 1);
        root->right = _createTree(nums, mid + 1, right);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return _createTree(nums, 0, nums.size() - 1);
    }
};

int main()
{
    vector<int> v1 = {-10, -3, 0, 5, 9};
    Solution().sortedArrayToBST(v1);
    system("pause");
    return 0;
}