#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob,
                               vector<int>& amount) {
            int n = amount.size(), maxIncome = INT_MIN;
            tree.resize(n);
            visited.assign(n, false);
            queue<vector<int>> q;
            q.push({0, 0, 0});
            for (vector<int> i : edges) {
                tree[i[0]].push_back(i[1]);
                tree[i[1]].push_back(i[0]);
            }
    
            findBobPath(bob, 0);
            visited.assign(n, false);
            while (!q.empty()) {
                int sourceNode = q.front()[0], time = q.front()[1],
                    income = q.front()[2];
                if (bobPath.find(sourceNode) == bobPath.end() ||
                    time < bobPath[sourceNode]) {
                    income += amount[sourceNode];
                } else if (time == bobPath[sourceNode]) {
                    income += (amount[sourceNode] / 2);
                }
                if (tree[sourceNode].size() == 1 && sourceNode != 0) {
                    maxIncome = max(maxIncome, income);
                }
                for (int adjacentNode : tree[sourceNode]) {
                    if (!visited[adjacentNode]) {
                        q.push({adjacentNode, time + 1, income});
                    }
                }
    
                visited[sourceNode] = true;
                q.pop();
            }
            return maxIncome;
        }
    
    private:
        unordered_map<int, int> bobPath;
        vector<bool> visited;
        vector<vector<int>> tree;
    
        bool findBobPath(int sourceNode, int time) {
            bobPath[sourceNode] = time;
            visited[sourceNode] = true;
    
            if (sourceNode == 0) {
                return true;
            }
    
            for (auto adjacentNode : tree[sourceNode]) {
                if (!visited[adjacentNode]) {
                    if (findBobPath(adjacentNode, time + 1)) {
                        return true;
                    }
                }
            }
            bobPath.erase(sourceNode);
            return false;
        }
    };