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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *start = head;
        if (head == NULL)
            return head;

        int count = 1;

        while (head->next != NULL)
        {
            head = head->next;
            count++;
        }

        k = k % count;
        head->next = start;

        for (int i = 1; i < count - k; i++)
        {
            start = start->next;
        }

        head = start->next;
        start->next = NULL;
        return head;
    }
};