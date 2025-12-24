#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    Node *mergeTwoLists(Node *list1, Node *list2)
    {
        if (!list1 || !list2)
            return list1 != NULL ? list1 : list2;
        Node* res;

        if(list1 -> data < list2 -> data) {
            res = list1;
            res -> bottom = mergeTwoLists(list1 -> bottom, list2);
            res -> next = NULL;
        }
        else {
            res = list2;
            res -> bottom = mergeTwoLists(list1, list2 -> bottom);
            res -> next = NULL;
        }

        return res;
    }
    Node *flatten(Node *root)
    {
        if (!root || !root->next)
            return root;
        root->next = flatten(root->next);

        root = mergeTwoLists(root, root->next);

        return root;
    }
};