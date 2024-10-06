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
    void count(TreeNode *root, int &counter)
    {
        if (root == NULL)
            return;

        count(root->left, counter);
        count(root->right, counter);
        counter++;
    }
    int countNodes(TreeNode *root)
    {
        int counter = 0;
        count(root, counter);
        return counter;
    }
};