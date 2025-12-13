#include <bits/stdc++.h>
using namespace std;

class NumberContainers
{
public:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> res;
    unordered_map<int, int> index_val;

    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        if (index_val.count(index))
        {
            int prevNum = index_val[index];
            if (prevNum == number)
                return;
            res[prevNum].push(INT_MAX);
        }
        res[number].push(index);
        index_val[index] = number;
    }

    int find(int number)
    {
        while (!res[number].empty() && index_val[res[number].top()] != number)
        {
            res[number].pop();
        }
        return res[number].empty() ? -1 : res[number].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */