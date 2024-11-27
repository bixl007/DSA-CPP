#include <bits/stdc++.h>
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
private:
    void solve(TreeNode *root, TreeNode *&ans)
    {
        if (root == NULL)
            return;

        solve(root->left, ans);
        ans->left = NULL;
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        solve(root->right, ans);
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *temp = new TreeNode(-1);
        TreeNode *ans = temp;
        solve(root, ans);
        return temp->right;
    }
};