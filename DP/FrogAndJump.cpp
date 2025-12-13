#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int unvisitedLeaves(int N, int leaves, int frogs[])
    {
        // Code here
        vector<bool> seive(leaves + 1, false);
        sort(frogs, frogs + N);

        for (int i = 0; i < N; i++)
        {
            int num = frogs[i];
            if(num > leaves || num == 0)
                continue;
            if (!seive[num])
            {
                seive[num] = true;
                for (int j = num; j <= leaves; j += num)
                {
                        seive[j] = true;
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i < leaves + 1; i++)
        {
            if (!seive[i])
                cnt++;
        }

        return cnt;
    }
};
