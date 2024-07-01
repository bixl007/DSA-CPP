#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Traversing LL
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Length of LL
int getLength(Node *&head)
{

    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        ++len;
        temp = temp->next;
    }
    return len;
}

// Insert to head
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

// Insert to tail
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

// Insert at a position
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
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    cout << "After inserting to head: " << endl;
    print(head);
    cout << "Length of the Linked list is: " << getLength(head) << endl;
    insertAtHead(head, 24);
    print(head);
    cout << "Length of the Linked list is: " << getLength(head) << endl;
    insertAtHead(head, 28);
    insertAtHead(head, 94);
    insertAtHead(head, 70);
    insertAtHead(head, 65);
    print(head);
    cout << "Length of the Linked list is: " << getLength(head) << endl;

    cout << "After inserting to tail: " << endl;
    insertAtTail(tail, 74);
    insertAtTail(tail, 62);
    insertAtTail(tail, 47);
    insertAtTail(tail, 56);
    print(head);
    cout << "Length of the Linked list is: " << getLength(head) << endl;

    insertAtPosition(tail, head, 4, 65);
    print(head);
    cout << "Length of the Linked list is: " << getLength(head) << endl;

    return 0;
}