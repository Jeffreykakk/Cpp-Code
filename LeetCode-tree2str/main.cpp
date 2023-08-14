#include <iostream>
#include <windows.h>
#include <string>

// 给你二叉树的根节点 root ，请你采用前序遍历的方式
// 将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串
// 空节点使用一对空括号对 "()" 表示
// 转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对

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
    string _tree2str(TreeNode *cur)
    {
        if (cur == nullptr)
            return string();
        string s;
        s += to_string(cur->val);

        if (cur->left || cur->right)
        {
            s += '(';
            s += _tree2str(cur->left);
            s += ')';
        }

        if (cur->right)
        {
            s += '(';
            s += _tree2str(cur->right);
            s += ')';
        }
        return s;
    }

    string tree2str(TreeNode *root)
    {
        return _tree2str(root);
    }
};

int main()
{
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    n1->left = n2;
    n1->right = n3;
    n2->right = n4;
    cout << Solution().tree2str(n1) << endl;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    system("pause");
    return 0;
}