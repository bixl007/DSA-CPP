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
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        dfs(root->left, root->right, 0);
        return root;
    }

    void dfs(TreeNode *left, TreeNode *right, int level)
    {
        if (left == NULL || right == NULL)
            return;
        if (level % 2 == 0)
        {
            swap(left->val, right->val);
        }
        dfs(left->left, right->right, level + 1);
        dfs(left->right, right->left, level + 1);
    }
};