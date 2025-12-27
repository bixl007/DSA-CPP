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
    TreeNode *solve(vector<int> &inorder, int iStart, int iEnd, vector<int> &postorder, int pStart, int pEnd, unordered_map<int, int> &mpp)
    {
        if (pStart > pEnd || iStart > iEnd)
            return NULL;

        TreeNode *root = new TreeNode(postorder[pEnd]);

        int inRoot = mpp[root->val];
        int numsLeft = inRoot - iStart;

        root->left = solve(inorder, iStart, inRoot - 1, postorder, pStart, pStart + numsLeft - 1, mpp);

        root->right = solve(inorder, inRoot + 1, iEnd, postorder, pStart + numsLeft, pEnd - 1, mpp);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size())
            return NULL;

        unordered_map<int, int> mpp;

        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        return solve(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mpp);
    }
};