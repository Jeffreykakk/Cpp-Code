#include <iostream>
#include <windows.h>
#include <vector>
#include <stack>

using namespace std;

// 非递归中序遍历二叉树

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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        if(root==nullptr)
        return v;
        stack<TreeNode*> st;
        TreeNode* cur=root;
        while(cur||!st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
            TreeNode* top=st.top();
            st.pop();
            v.push_back(top->val);
            cur=top->right;
        }
        return v;
    }
};

int main()
{
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(5);
    TreeNode *n4 = new TreeNode(1);
    TreeNode *n5 = new TreeNode(3);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    vector<int> v = Solution().inorderTraversal(n1);
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    system("pause");
    return 0;
}