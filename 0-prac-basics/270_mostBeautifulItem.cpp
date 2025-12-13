#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        int maxi = INT_MAX;
        vector<vector<int>> res = {{0, 0, maxi}};
        sort(items.begin(), items.end());

        for (auto &item : items)
        {
            int price = item[0];
            int beauty = item[1];
            if (beauty > res.back()[1])
            {
                res.back()[2] = price;
                res.push_back({price, beauty, maxi});
            }
        }

        vector<int> ans;

        for (int x : queries)
        {
            for (int i = res.size() - 1; i >= 0; i--)
            {
                if (res[i][0] <= x)
                {
                    ans.push_back(res[i][1]);
                    break;
                }
            }
        }
        return ans;
    }
};