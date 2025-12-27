#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class NewNode
{
public:
    int mini;
    int maxi;
    int size;

    NewNode(int mini, int maxi, int size)
    {
        this->mini = mini;
        this->maxi = maxi;
        this->size = size;
    }
};

class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NewNode *solve(Node *root)
    {
        if (!root)
        {
            NewNode *temp = new NewNode(INT_MAX, INT_MIN, 0);
            return temp;
        }

        NewNode *left = solve(root->left);
        NewNode *right = solve(root->right);

        if (root->data > left->maxi && root->data < right->mini)
        {
            return new NewNode(min(root->data, left->mini), max(root->data, right->maxi), 1 + left->size + right->size);
        }
        else
            return new NewNode(INT_MIN, INT_MAX, max(left -> size, right -> size));
    }
    int largestBst(Node *root)
    {
        // Your code here
        NewNode *curr = solve(root);
        return curr->size;
    }
};