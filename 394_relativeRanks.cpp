#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        priority_queue<pair<int, int>> pq;
        int n = score.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({score[i], i});
        }
        vector<string> res(n);
        int pos = 1;
        while (!pq.empty())
        {
            int idx = pq.top().second;
            pq.pop();
            if (pos == 1)
            {
                res[idx] = "Gold Medal";
            }
            else if (pos == 2)
            {
                res[idx] = "Silver Medal";
            }
            else if (pos == 3)
            {
                res[idx] = "Bronze Medal";
            }
            else
            {
                res[idx] = to_string(pos);
            }
            pos++;
        }
        return res;
    }
};