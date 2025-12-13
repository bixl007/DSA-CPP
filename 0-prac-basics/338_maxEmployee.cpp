#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumInvitations(vector<int> &favorite)
    {
        int n = favorite.size(), maxCycle = 0, pairChain = 0;
        queue<int> q;
        vector<bool> vis(n);
        vector<int> inDeg(n), chainLen(n);

        for (int x : favorite)
            inDeg[x]++;

        for (int i = 0; i < n; i++)
            if (!inDeg[i])
                q.push(i);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = true;
            int nbr = favorite[u];
            chainLen[nbr] = max(chainLen[nbr], chainLen[u] + 1);
            if (--inDeg[nbr] == 0)
                q.push(nbr);
        }

        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;

            int cycleLen = 0, u = i;

            while (!vis[u])
            {
                vis[u] = true;
                u = favorite[u];
                cycleLen++;
            }

            if (cycleLen == 2)
                pairChain += 2 + chainLen[i] + chainLen[favorite[i]];
            else
                maxCycle = max(maxCycle, cycleLen);
        }
        return max(maxCycle, pairChain);
    }
};