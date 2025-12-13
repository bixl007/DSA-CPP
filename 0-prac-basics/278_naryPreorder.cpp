#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> output;
    void traverse(Node *root)
    {
        if (root == NULL)
            return;
        output.push_back(root->val);
        for (auto i : root->children)
            traverse(i);
    }
    vector<int> preorder(Node *root)
    {
        output.clear();
        traverse(root);
        return output;
    }
};