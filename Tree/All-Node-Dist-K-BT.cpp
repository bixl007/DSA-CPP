#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void findParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (!root)
            return;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (!root)
            return {};
        unordered_map<TreeNode *, TreeNode *> parent;
        unordered_map<TreeNode *, bool> visited;
        findParent(root, parent);

        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int lvl = 0;
        vector<int> res;

        while (!q.empty())
        {
            int size = q.size();

            if (lvl++ == k)
                break;

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left] = 1;
                }
                if (curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right] = 1;
                }
                if (parent[curr] && !visited[parent[curr]])
                {
                    q.push(parent[curr]);
                    visited[parent[curr]] = 1;
                }
            }
        }

        while (!q.empty())
        {
            res.push_back(q.front() -> val);
            q.pop();
        }

        return res;
    }
};

