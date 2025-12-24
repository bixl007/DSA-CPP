#include <bits/stdc++.h>
using namespace std;

// a Node of the doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

class Solution
{
public:
    void deleteAllOccurOfX(struct Node **head_ref, int x)
    {
        // Write your code here
        struct Node *temp = *head_ref;

        while (temp)
        {
            if (temp->data == x)
            {
                struct Node *prev = temp->prev;
                struct Node *next = temp->next;

                if (prev)
                {
                    prev->next = temp->next;
                }
                else
                {
                    *head_ref = next;
                }

                if (next)
                {
                    next->prev = prev;
                }

                free(temp);
                temp = next;
            }
        }
    }
};
