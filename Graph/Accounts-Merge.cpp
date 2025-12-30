#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
public:
    vector<int> parent, size;
    Disjoint(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1);

        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionSize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_v] < size[ulp_u])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        Disjoint dj(n);
        unordered_map<string, int> mailNode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mailNode.find(accounts[i][j]) == mailNode.end())
                {
                    mailNode[accounts[i][j]] = i;
                }
                else
                {
                    dj.unionSize(i, mailNode[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> mergeMail(n);

        for (auto it : mailNode)
        {
            string mail = it.first;
            int node = dj.findUPar(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++)
        {
            if (mergeMail[i].size() == 0)
                continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergeMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};