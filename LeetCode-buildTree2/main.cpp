#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

// 给定两个整数数组 inorder 和 postorder
// 其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历
// 请构造二叉树并返回其根节点

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
public:
    TreeNode *_buildTree(vector<int> &inorder, vector<int> &postorder, int &posi, int begin, int end)
    {
        if (begin > end)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[posi--]);
        int ini = end;
        while (root->val != inorder[ini])
            ini--;
        root->right = _buildTree(inorder, postorder, posi, ini + 1, end);
        root->left = _buildTree(inorder, postorder, posi, begin, ini - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int posi = postorder.size() - 1;
        return _buildTree(inorder, postorder, posi, 0, inorder.size() - 1);
    }
};

int main()
{
    vector<int> v1{9, 3, 15, 20, 7};
    vector<int> v2{9, 15, 7, 20, 3};

    TreeNode *root = Solution().buildTree(v1, v2);

    system("pause");
    return 0;
}