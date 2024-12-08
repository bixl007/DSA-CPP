#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int maxTwoEvents(vector<vector<int>> &events)
    {
        const int n = events.size();
        vector<uint64_t> time(n * 2);
        for (int i = 0; i < n; i++)
        {
            int s = events[i][0], e = events[i][1], v = events[i][2];
            time[2 * i] = ((uint64_t)s << 21) + v;
            time[2 * i + 1] = ((uint64_t)e << 21) + (1 << 20) + v;
        }
        sort(time.begin(), time.end());
        int ans = 0, maxV = 0, n2 = n * 2;
        for (auto info : time)
        {
            bool isEnd = (info >> 20) & 1;
            int v = info & ((1 << 20) - 1);
            if (isEnd)
                maxV = max(maxV, v);
            else
                ans = max(ans, maxV + v);
        }
        return ans;
    }
};
