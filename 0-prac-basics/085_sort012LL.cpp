/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

// Approach 1 - BY COUNTING AND REPLACING THE VALUES

// Node* sortList(Node *head){
    
//     int countZero = 0;
//     int countOne = 0;
//     int countTwo = 0;

//     Node *temp = head;

//     while(temp != NULL){
//         if(temp->data == 0)
//             countZero++;
//         if(temp->data == 1)
//             countOne++;
//         if(temp->data == 2)
//             countTwo++;
//         temp = temp -> next;
//     }

//     temp = head;

//     while(temp != NULL) {
//         if(countZero != 0){
//             temp -> data = 0;
//             countZero--;
//         }
//         else if(countOne != 0){
//             temp -> data = 1;
//             countOne--;
//         }
//         else{
//             temp -> data = 2;
//             countTwo--;
//         }
//         temp = temp -> next;
//     }
//     return head;
// }

// APPROACH 2 - BY CREATING DIFFERENT LL FOR EACH NUMBERS AND THEN MERGING

// void insertAtTail(Node *&tail, Node *curr) {
//     tail -> next = curr;
//     tail = curr;
// }


// Node *sortList(Node *head) {
//     Node* zeroHead = new Node(-1);
//     Node* zeroTail = zeroHead;
//     Node* oneHead = new Node(-1);
//     Node* oneTail = oneHead;
//     Node* twoHead = new Node(-1);
//     Node* twoTail = twoHead;

//     Node *curr = head;

//     while(curr != NULL) {
//         int value = curr -> data;

//         if(value == 0) {
//             insertAtTail(zeroTail, curr);
//         }
//         else if (value == 1) {
//             insertAtTail(oneTail, curr);
//         } else if (value == 2) {
//             insertAtTail(twoTail, curr);
//         }
//         curr = curr->next;
//     }

//     if(oneHead -> next != NULL) {
//         zeroTail -> next = oneHead -> next;
//     }
//     else{
//         zeroTail -> next = twoHead -> next; 
//     }
//     oneTail -> next = twoHead -> next;
//     twoTail -> next = NULL;
    
//     head = zeroHead -> next;

//     delete zeroHead;
//     delete oneHead;
//     delete twoHead;

//     return head;
// }