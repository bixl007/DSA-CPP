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
    TreeNode *solve(vector<int> &preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd, unordered_map<int, int> &mpp)
    {
        if (pStart > pEnd || iStart > iEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[pStart]);
        int inRoot = mpp[root->val];
        int numsLeft = inRoot - iStart;

        root->left = solve(preorder, pStart + 1, pStart + numsLeft, inorder, iStart, inRoot - 1, mpp);
        root->right = solve(preorder, pStart + numsLeft + 1, pEnd, inorder, inRoot + 1, iEnd, mpp);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mpp;

        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        TreeNode *root = solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
        return root;
    }
};