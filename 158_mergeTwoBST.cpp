#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void convertIntoSortedDLL(TreeNode *root, TreeNode *&head)
{
    if (root == NULL)
        return;

    convertIntoSortedDLL(root->right, head);
    root->right = head;

    if (head != NULL)
        head->left = root;

    head = root;
    convertIntoSortedDLL(root->left, head);
}

TreeNode *mergeLists(TreeNode *head1, TreeNode *head2)
{

    TreeNode *head = NULL;
    TreeNode *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNode(TreeNode *head)
{
    int cnt = 0;
    TreeNode *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode *sortedLLToBST(TreeNode *&head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    TreeNode *left = sortedLLToBST(head, n / 2);

    TreeNode *root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n - n / 2 - 1);
    return root;
}

std::vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    TreeNode *head1 = NULL;
    TreeNode *head2 = NULL;

    convertIntoSortedDLL(root1, head1);
    convertIntoSortedDLL(root2, head2);

    TreeNode *result = mergeLists(head1, head2);

    TreeNode *temp = result;
    std::vector<int> v;

    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->right;
    }

    return v;
}