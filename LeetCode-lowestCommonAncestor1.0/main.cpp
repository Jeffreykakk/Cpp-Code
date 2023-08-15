#include <iostream>
#include <windows.h>
#include <vector>
#include <queue>

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
    bool find(TreeNode* root, TreeNode* x)
    {
        if(root==nullptr)
        return false;
        if(root==x)
        return true;
        return find(root->left,x) || find(root->right,x);

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==p || root==q)
        return root;
        bool pInLeft,pInRight,qInleft,qInright;
        pInLeft=find(root->left,p);
        pInRight=!pInLeft;
        qInleft=find(root->left,q);
        qInright=!qInleft;
        if( (pInLeft && qInright) || (pInRight && qInleft) )
        return root;
        else if(pInLeft && qInleft)
        return lowestCommonAncestor(root->left,p,q); 
        else
        return lowestCommonAncestor(root->right,p,q);
    }
};

int main()
{
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(5);
    TreeNode *n3 = new TreeNode(1);
    TreeNode *n4 = new TreeNode(6);
    TreeNode *n5 = new TreeNode(2);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    cout << Solution().lowestCommonAncestor(n1,n4,n5)->val << endl;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    system("pause");
    return 0;
}