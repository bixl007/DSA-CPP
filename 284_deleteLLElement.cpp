#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *res = temp;
        ;

        while (temp->next != NULL)
        {
            if (temp->next->val != val)
            {
                temp = temp->next;
            }
            else
            {
                temp->next = temp->next->next;
            }
        }

        return res->next;
    }
};