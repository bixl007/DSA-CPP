#include <iostream>
#include <queue>
using namespace std;

int main()
{

    queue<int> q;

    q.push(11);
    cout << "Front of queue is: " << q.front() << endl;

    q.push(12);
    q.push(14);
    q.push(18);

    cout << "Size of queue is: " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout << "Size of queue is: " << q.size() << endl;

    if (q.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
}