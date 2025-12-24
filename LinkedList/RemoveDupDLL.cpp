#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        // Your code here
        struct Node *temp = head;

        while (temp)
        {
            struct Node *curr = temp->next;

            while (curr && curr->data == temp->data)
            {
                struct Node *freeMem = curr;
                curr = curr->next;
                free(freeMem);
            }
            if (curr)
                curr->prev = temp;
            temp->next = curr;

            temp = temp->next;
        }
        return head;
    }
};