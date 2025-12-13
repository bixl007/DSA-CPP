#include <iostream>
using namespace std;

class kQueue
{

public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;

public:
    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        arr = new int[n];
        freeSpot = 0;
    }

    ~kQueue()
    {
        delete[] front;
        delete[] rear;
        delete[] arr;
        delete[] next;
    }

    void enqueue(int data, int qn)
    {

        if (freeSpot == -1)
        {
            cout << "No empty space is present" << endl;
            return;
        }
        int index = freeSpot;

        freeSpot = next[index];

        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            next[rear[qn - 1]] = index;
        }

        next[index] = -1;

        rear[qn - 1] = index;

        arr[index] = data;
    }

    int dequeue(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int index = front[qn - 1];
        front[qn - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main()
{

    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}