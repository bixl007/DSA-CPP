#include <bits/stdc++.h>
using namespace std;

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
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (head == NULL)
            return NULL;

        ListNode *temp = new ListNode(0, head);
        ListNode *prev = temp;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            bool duplicate = false;

            while (curr->next != nullptr && curr->val == curr->next->val)
            {
                duplicate = true;
                curr = curr->next;
            }

            if (duplicate)
            {
                prev->next = curr->next;
            }
            else
            {
                prev = prev->next;
            }

            curr = curr->next;
        }

        return temp->next;
    }
};