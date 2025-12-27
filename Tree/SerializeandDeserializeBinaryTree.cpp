#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string st = "";
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                st += "#,";
            }
            else
            {
                st += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return st;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        queue<TreeNode *> q;
        TreeNode *node = new TreeNode(stoi(str));
        q.push(node);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            getline(s, str, ',');
            if (str != "#")
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str != "#")
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));