//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
#include <vector>
/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Approach 1 - copying and checking in a new array
/*
class Solution
{
private:
    bool checkP(vector<int> arr)
    {
        int s = 0;
        int n = arr.size() - 1;

        while (s <= n)
        {
            if (arr[s] != arr[n])
                return false;
            s++;
            n--;
        }
        return true;
    }

public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int> ans;

        while (head != NULL)
        {
            ans.push_back(head->data);
            head = head->next;
        }
        return checkP(ans);
    }
};
*/

//{ Driver Code Starts.
/* Driver program to test above function*/
/*
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}
*/

// } Driver Code Ends

// Approach 2

// class Solution{
//   private:
//     Node *getMid(Node *head){
//         Node *slow = head;
//         Node *fast = head -> next;

//         while(fast != NULL && fast -> next != NULL) {
//             fast = fast -> next -> next;
//             slow = slow -> next;
//         }

//         return slow;
//     }

//     Node * reverse(Node* head) {

//         Node* curr = head;
//         Node* prev = NULL;
//         Node* next = NULL;

//         while(curr != NULL){
//             next = curr -> next;
//             curr -> next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     }

//   public:
//     //Function to check whether the list is palindrome.
//     bool isPalindrome(Node *head)
//     {
//         if(head -> next == NULL) return true;

//         Node *middle = getMid(head);

//         Node* temp = middle -> next;
//         middle -> next = reverse(temp);

//         Node* head1 = head;
//         Node* head2 = middle -> next;

//         while(head2 != NULL) {
//             if(head2 -> data != head1 -> data){
//                 return 0;
//             }
//             head1 = head1 -> next;
//             head2 = head2 -> next;
//         }

//         temp = middle -> next;
//         middle -> next = reverse(temp);

//         return true;

//     }
// };