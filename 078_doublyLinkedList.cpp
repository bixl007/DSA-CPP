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
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
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
void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Insert to tail
void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {

        Node *temp = new Node(d);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

// Insert at a position
void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
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
        insertAtTail(head, tail, d);
        return;
    }

    // Creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// Deleting a node
void deleteNode(int position, Node *&head, Node *&tail)
{

    // Deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    // Deleting any middle node or last node
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
        if (prev->next == NULL)
        {
            tail = prev;
        }
    }
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    cout << "After inserting to head: " << endl;
    print(head);
    cout << "Length of the Linked list is: " << getLength(head) << endl;
    insertAtHead(head, tail, 24);
    print(head);
    cout << "Length of the Linked list is: " << getLength(head) << endl;
    insertAtHead(head, tail, 28);
    insertAtHead(head, tail, 94);
    insertAtHead(head, tail, 70);
    insertAtHead(head, tail, 65);
    print(head);
    cout << "Length of the Linked list is: " << getLength(head) << endl;

    cout << "After inserting to tail: " << endl;
    insertAtTail(head, tail, 74);
    insertAtTail(head, tail, 62);
    insertAtTail(head, tail, 47);
    insertAtTail(head, tail, 56);
    print(head);
    cout << "Length of the Linked list is: " << getLength(head) << endl;

    insertAtPosition(tail, head, 4, 65);
    print(head);
    cout << "Length of the Linked list is: " << getLength(head) << endl;

    cout << "Deleting a node" << endl;
    deleteNode(2, head, tail);
    print(head);
    cout << "Length of the Linked list is: " << getLength(head) << endl;

    return 0;
}