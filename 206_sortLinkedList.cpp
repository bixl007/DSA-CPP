#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> arr;
        ListNode *temp = head;

        while (temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        for (auto i : arr)
        {
            cout << i << endl;
        }

        sort(arr.begin(), arr.end());

        ListNode *header = head;

        int i = 0;
        while (header != NULL)
        {
            header->val = arr[i++];
            header = header->next;
        }

        return head;
    }
};