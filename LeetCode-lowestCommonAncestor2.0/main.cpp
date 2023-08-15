#include <iostream>
#include <windows.h>
#include <stack>

using namespace std;

// 给定一个二叉树，找到该树中两个指定节点的最近公共祖先

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
    bool FindPath(TreeNode *root, TreeNode *x, stack<TreeNode *> &st)
    {
        if (root == nullptr)
            return false;
        st.push(root);
        if (root == x)
            return true;
        if (FindPath(root->left, x, st) == false && FindPath(root->right, x, st) == false)
        {
            st.pop();
            return false;
        }
        else
            return true;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        stack<TreeNode *> pPath;
        stack<TreeNode *> qPath;
        FindPath(root, p, pPath);
        FindPath(root, q, qPath);
        stack<TreeNode *> longst = pPath;
        stack<TreeNode *> shortst = qPath;
        if (longst.size() < shortst.size())
        {
            longst = qPath;
            shortst = pPath;
        }
        while (longst.size() != shortst.size())
            longst.pop();
        while (longst.top() != shortst.top())
        {
            longst.pop();
            shortst.pop();
        }
        return longst.top();
    }
};

int main()
{
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(5);
    TreeNode *n3 = new TreeNode(1);
    TreeNode *n4 = new TreeNode(6);
    TreeNode *n5 = new TreeNode(2);
    TreeNode *n6 = new TreeNode(0);
    TreeNode *n7 = new TreeNode(8);
    TreeNode *n8 = new TreeNode(7);
    TreeNode *n9 = new TreeNode(4);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n5->left = n8;
    n5->right = n9;
    cout << Solution().lowestCommonAncestor(n1, n2, n9)->val << endl;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    system("pause");
    return 0;
}