#include <bits/stdc++.h>
using namespace std;

// Priority-queue approach

class Solution
{
public:
    double minMaxDist(vector<int> &stations, int K)
    {
        // Code here
        int n = stations.size();
        vector<int> cnt(n - 1, 0);
        priority_queue<pair<double, int>> pq;

        for (int i = 0; i < n - 1; i++)
        {
            pq.push({stations[i + 1] - stations[i], i});
        }

        for (int i = 1; i <= K; i++)
        {
            auto val = pq.top();
            pq.pop();

            int secInd = val.second;
            cnt[secInd]++;

            double iniDiff = stations[secInd + 1] - stations[secInd];
            double newSecLen = iniDiff / (double)(cnt[secInd] + 1);

            pq.push({newSecLen, secInd});
        }

        return pq.top().first;
    }
};

// Binary Search Approach
class Solution
{
public:
    bool check(double mid, vector<int> &stations, int k)
    {
        int cnt = 0;
        int n = stations.size();

        for (int i = 0; i < n - 1; i++)
        {
            double diff = stations[i + 1] - stations[i];

            int needed = (int)((diff / mid));

            if (mid * needed == diff)
                needed--;
            cnt += needed;
        }

        return cnt <= k;
    }
    double minMaxDist(vector<int> &stations, int K)
    {
        // Code here
        int n = stations.size();
        double low = 0, high = 0;

        for (int i = 0; i < n - 1; i++)
        {
            high = max(high, (double)(stations[i + 1] - stations[i]));
        }

        double ans = high;
        while (high - low > 1e-6)
        {
            double mid = low + (high - low) / 2.0;

            if (check(mid, stations, K))
            {
                ans = mid;
                high = mid;
            }
            else
                low = mid;
        }

        return ans;
    }
};