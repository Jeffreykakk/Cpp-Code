#include <iostream>
#include <windows.h>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> vv;
        if (root == nullptr)
            return vv;
        queue<TreeNode *> q;
        q.push(root);
        int size = 1;
        while (!q.empty())
        {
            vector<int> v;
            for (size_t i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
                v.push_back(front->val);
            }
            vv.push_back(v);
            size = q.size();
        }
        return vv;
    }
};

int main()
{
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(20);
    TreeNode *n4 = new TreeNode(15);
    TreeNode *n5 = new TreeNode(7);
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;
    vector<vector<int>> vv = Solution().levelOrder(n1);
    for (size_t i = 0; i < vv.size(); i++)
    {
        size_t sz = vv[i].size();
        for (size_t j = 0; j < sz; j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    system("pause");
    return 0;
}