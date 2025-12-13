// Coding ninja remove duplicate form unsorted linked list

// #include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

// Node *removeDuplicates(Node *head)
// {
//     if(head == NULL) return NULL;

//     unordered_map<int, bool> visited;
//     Node *current = head;
//     Node *prev = NULL;

//     while(current != NULL) {
//         if(visited[current -> data] == true) {
//             prev -> next = current -> next;
//             delete current;
//         }
//         else{
//             visited[current -> data] = true;
//             prev = current;
//         }
//         current = prev -> next;
//     }
//     return head;
// }

