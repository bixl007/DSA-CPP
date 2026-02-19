#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &itr : rooms[node])
            {
                if (!vis[itr])
                {
                    vis[itr] = 1;
                    q.push(itr);
                }
            }
        }

        for (auto i : vis)
        {
            if (!i)
            {
                return false;
            }
        }

        return true;
    }
};