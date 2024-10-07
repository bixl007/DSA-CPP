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
    void solve(TreeNode *root, set<int> &arr1)
    {
        if (root == NULL)
            return;
        solve(root->left, arr1);
        solve(root->right, arr1);
        arr1.insert(root->val);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        set<int> arr1;
        vector<int> res;

        solve(root, arr1);
        int diff = INT_MAX;

        for (auto i : arr1)
        {
            res.push_back(i);
        }

        for (int i = 1; i < res.size(); i++)
        {
            diff = min(diff, res[i] - res[i - 1]);
        }
        return diff;
    }
};