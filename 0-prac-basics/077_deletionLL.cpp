#include <iostream>
using namespace std;

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

// Destructor
~Node() {
    int value = this->data;
    if(this->next != NULL) {
        delete next;
        this->next = NULL;
    }
}
};


void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // Creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head, Node *&tail) {

    // Deleting first or start node
    if (position == 1)
    {
        Node* temp = head;
        head = head -> next;
        // Memory free start node
        temp -> next = NULL;
        delete temp;
    }

    // Deleting any middle node or last node
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }


        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        if(prev->next == NULL) {
            tail = prev;
        }
        
    }
    
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    cout << "Before inserting " << endl;
    Node *node2 = new Node(40);
    Node *head = node2;
    Node *tail = node2;
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 70);
    insertAtTail(tail, 80);
    insertAtTail(tail, 90);

    cout << "Original Linked List" << endl;
    insertAtPosition(tail, head, 4, 65);
    print(head);

    cout << "After deletion" << endl;
    deleteNode(7, head, tail);
    print(head);

    cout << "value at head: " << head->data << endl;
    cout << "value at tail: " << tail->data << endl;

    return 0;
}