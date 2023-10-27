#include <vector>
#include <windows.h>
#include <iostream>

// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树

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
public:
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    bool isValidBST(TreeNode *root)
    {
        vector<int> v;
        inorder(root, v);
        int i = 0;
        while (i < v.size() - 1)
        {
            if (v[i] >= v[i + 1])
                return false;
            i++;
        }
        return true;
    }
};

int main()
{
    TreeNode *n1 = new TreeNode(32);
    TreeNode *n2 = new TreeNode(26);
    TreeNode *n3 = new TreeNode(47);
    TreeNode *n4 = new TreeNode(19);
    TreeNode *n5 = new TreeNode(56);
    TreeNode *n6 = new TreeNode(27);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->right = n5;
    n4->right = n6;
    cout << Solution().isValidBST(n1) << endl;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    system("pause");
    return 0;
}