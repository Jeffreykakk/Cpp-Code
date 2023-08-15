#include <iostream>
#include <windows.h>
#include <vector>
#include <queue>

using namespace std;

// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表
// 要求不能创建任何新的节点，只能调整树中节点指针的指向

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
    void Inorder(TreeNode *root, TreeNode *&prev)
    {
        if (root == nullptr)
            return;
        Inorder(root->left, prev);
        root->left = prev;
        if (prev)
            prev->right = root;
        prev = root;
        Inorder(root->right, prev);
    }

    TreeNode *treeToDoublyList(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *ptr = nullptr;
        Inorder(root, ptr);
        TreeNode *head = root;
        while (head->left)
            head = head->left;
        TreeNode *tail = root;
        while (tail->right)
            tail = tail->right;
        head->left = tail;
        tail->right = head;
        return head;
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
    TreeNode *head = Solution().treeToDoublyList(n1);
    TreeNode *cur = head;
    while(1)
    {
        cout<<cur->val<<" ";
        cur = cur->right;
        if(cur==head)
            break;
    }
    cout << endl;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    system("pause");
    return 0;
}