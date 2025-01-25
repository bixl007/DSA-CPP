#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<pair<int, int>> nums2(n);
        for (int i = 0; i < n; i++)
        {
            nums2[i] = {nums[i], i};
        }

        sort(nums2.begin(), nums2.end());
        vector<vector<int>> indices;

        for (int i = 0; i < n; i++)
        {
            if (i == 0 || nums2[i].first - nums2[i - 1].first > limit)
            {
                indices.push_back({});
            }
            indices.back().push_back(nums2[i].second);
        }

        vector<int> res(n);

        for (auto &i : indices)
        {
            vector<int> sortedIndex(i);
            sort(sortedIndex.begin(), sortedIndex.end());

            for (int j = 0; j < i.size(); j++)
            {
                res[sortedIndex[j]] = nums[i[j]];
            }
        }

        return res;
    }
};