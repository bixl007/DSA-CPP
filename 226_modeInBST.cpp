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
    void solve(TreeNode *&root, unordered_map<int, int> &counter)
    {
        if (root == NULL)
        {
            return;
        }
        solve(root->left, counter);
        counter[root->val]++;
        solve(root->right, counter);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        unordered_map<int, int> counter;
        vector<int> ans;
        solve(root, counter);

        int maxi = INT_MIN;

        for (auto i : counter)
        {
            if (i.second > maxi)
            {
                maxi = i.second;
            }
        }

        for (auto i : counter)
        {
            if (i.second == maxi)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};