#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int n = events.size();

        sort(events.begin(), events.end());

        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--)
        {
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int left = i + 1, right = n - 1;
            int nextEventIdx = -1;

            int targetStart = events[i][1] + 1;

            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (events[mid][0] >= targetStart)
                {
                    nextEventIdx = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            int currentTotal = events[i][2];

            if (nextEventIdx != -1)
            {
                currentTotal += suffixMax[nextEventIdx];
            }

            ans = max(ans, currentTotal);
        }

        return ans;
    }
};