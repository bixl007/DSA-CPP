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

void reverseLl(Node *&head)
{
    if (head == NULL)
        return;

    reverseLl(head->next);

    cout << head->data << " ";
}

int main()
{

    // cout << "After inserting at head" << endl;
    // Node *node1 = new Node(10);

    // Node *head = node1;
    // print(head);

    // insertAtHead(head, 20);

    // print(head);

    // insertAtHead(head, 30);
    // print(head);

    cout << "After inserting at tail" << endl;
    Node *node2 = new Node(40);
    Node *head = node2;
    Node *tail = node2;
    print(head);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    print(head);

    reverseLl(head);
    cout << endl;

    return 0;
}
