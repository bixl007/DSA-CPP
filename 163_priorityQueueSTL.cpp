#include <iostream>
#include <queue>
using namespace std;

int main()
{

    // Max heap

    priority_queue<int> pq;
    pq.push(10);
    pq.push(2);
    pq.push(5);
    pq.push(20);
    pq.push(12);
    cout << "Top element : " << pq.top() << endl;
    pq.pop();
    cout << "Size of pq : " << pq.size() << endl;

    // Min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(20);
    minHeap.push(12);
    cout << "Top element : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Size of pq : " << minHeap.size() << endl;

    return 0;
}
