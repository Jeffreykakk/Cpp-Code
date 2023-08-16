#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

// 给定两个整数数组 preorder 和 inorder 
// 其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历
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
    TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder, int& prei, int begin, int end)
    {
        if (begin > end)
            return nullptr;
        // 确定根节点
        TreeNode *root = new TreeNode(preorder[prei++]);
        int ini = begin;
        // 以根节点分割左右子树
        while (root->val != inorder[ini])
            ini++;
        // [begin,ini-1] ini [ini+1,end]
        root->left = _buildTree(preorder, inorder, prei, begin, ini - 1);
        root->right = _buildTree(preorder, inorder, prei, ini + 1, end);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int prei = 0;
        return _buildTree(preorder, inorder,prei , 0, inorder.size() - 1);
    }
};

int main()
{
    vector<int> v1{3, 9, 20, 15, 7};
    vector<int> v2{9,3,15,20,7};
    TreeNode *root = Solution().buildTree(v1,v2);
    
    system("pause");
    return 0;
}