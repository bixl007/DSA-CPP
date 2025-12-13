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

/*
int getLength(Node *head) {
    int len = 0;
    while(head != NULL){
        len++;
        head = head -> next;
    }
    return len;
}

Node *getMiddle(Node *head){
    if(head == NULL || head -> next == NULL) return head;

    if(head -> next -> next == NULL) {
        return head -> next;
    }

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;

}
*/

// Node *findMiddle(Node *head) {

//     return getMiddle(head);

    /*
    int len = getLength(head);
    int ans = (len / 2) ;

    Node *temp = head;
    int cnt = 0;
    while(cnt < ans) {
        temp = temp -> next;
        cnt++;
    }
    return temp;
}

    */
