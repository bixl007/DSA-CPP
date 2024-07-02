//              Coding ninja k reverse list 

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

// Node* kReverse(Node* head, int k) {
//     if(head == NULL) return NULL;

//     int len =0;
//     Node* check = head;
//      while(check != NULL){
//         len++;
//         check = check->next;
//     }

//     if(len<k ){

//         return head;

//     }

//     Node *next = NULL;
//     Node *curr = head;
//     Node *prev = NULL;
//     int count = 0;

//     while(curr != NULL && count < k) {
//         next = curr -> next;
//         curr -> next = prev;
//         prev = curr;
//         curr = next;
//         count++;
//     }

//     if(next != NULL) {
//         head -> next = kReverse(next, k);
//     }

//     return prev;
    
// }