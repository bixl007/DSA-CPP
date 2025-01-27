#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>> &prerequisites,
                                     vector<vector<int>> &queries)
    {
        unordered_map<int, unordered_set<int>> reachable;

        for (auto &i : prerequisites)
        {
            reachable[i[1]].insert(i[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            for (int j = 0; j < numCourses; ++j)
            {
                if (reachable[j].count(i))
                {
                    reachable[j].insert(reachable[i].begin(),
                                        reachable[i].end());
                }
            }
        }

        vector<bool> result;
        for (auto &i : queries)
        {
            result.push_back(reachable[i[1]].count(i[0]) > 0);
        }
        return result;
    }
};