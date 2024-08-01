// #include <queue>
// /*
// Following is the class structure of the Node class:

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node()
//     {
//         this->data = 0;
//         next = NULL;
//     }
//     Node(int data)
//     {
//         this->data = data; 
//         this->next = NULL;
//     }
//     Node(int data, Node* next)
//     {
//         this->data = data;
//         this->next = next;
//     }
// };
// */


// class Compare {
//     public:
//     bool operator() (Node *a, Node* b){
//         return a->data > b-> data;
//     }
// };

// Node* mergeKLists(vector<Node*> &listArray){
//     // Write your code here.
//     priority_queue<Node*, vector<Node*>, Compare> pq;

//     for(Node* listHead : listArray) {
//         if(listHead != NULL) {
//             pq.push(listHead);
//         }
//     }

//     Node* result = new Node(0);
//     Node* ans = result;

//     Node* temp;

//     while(!pq.empty()) {
//         temp = pq.top();
//         pq.pop();

//         ans -> next = temp;
//         ans = ans -> next;

//         if(temp -> next != NULL) {
//             pq.push(temp -> next);
//         }
//     }
//     return result -> next;
// }
