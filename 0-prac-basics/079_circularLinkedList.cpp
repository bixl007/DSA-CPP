#include <iostream>
using namespace std;
#include <map>

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data" << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{

    // Empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non empty list
        // assuming that the element is present int the list
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // Element found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    Node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

void deleteNode(Node *&tail, int value)
{

    // empty list
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {

        // Non empty list, assuming that value is present in the linked list
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // 1 NODE linked list
        if (curr == prev)
        {
            tail = NULL;
        }

        // >=2 Nodes linked list
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

bool isCircular(Node *head) // in parameter we can give any name
{
    if (head == NULL)
        return true;

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }
    return false;
}

bool detectLoop(Node *head)
{
    if (head == NULL)
        return false;

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
            return true;

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *floydDetectionLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL & fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if (slow == fast)
        {
            cout << "Present at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

Node *getStartingNode(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *intersection = floydDetectionLoop(head);
    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeLoop(Node *head)
{
    if (head == NULL)
        return;

    Node *startOfLoop = getStartingNode(head);
    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 5);
    print(tail);

    if (isCircular(tail))
        cout << "It is a circular list" << endl;

    if (detectLoop(tail))
        cout << "Loop is present!!" << endl;

    if (detectLoop(tail))
        cout << "Loop is present!!" << endl;

    if (floydDetectionLoop(tail) != NULL)
    {
        cout << "Loop is present!!" << endl;
    }
    else
    {
        cout << "No cycle is preset" << endl;
    }

    Node *startingNode = getStartingNode(tail);
    cout << "Loop starts at " << startingNode->data << endl;

    removeLoop(tail);
    print(tail);
}