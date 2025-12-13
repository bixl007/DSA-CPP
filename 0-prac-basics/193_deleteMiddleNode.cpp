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
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *mover = head;
        int count = 0;

        while (mover != NULL)
        {
            count++;
            mover = mover->next;
        }
        // cout << count << endl;
        // return head;

        if (count == 1)
            return NULL;

        int position = count / 2 + 1;

        ListNode *temp1 = head;
        ListNode *temp2 = head->next;
        count = 0;
        while (temp2 != NULL)
        {
            count++;
            if (count == position - 1)
            {
                if (temp2->next == NULL)
                {
                    temp1->next = NULL;
                }
                else
                {
                    temp1->next = temp2->next;
                    temp2->next = NULL;
                    break;
                }
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return head;
    }
};