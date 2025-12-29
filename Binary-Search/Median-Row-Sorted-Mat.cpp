#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int median(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        int req = n * m / 2;

        for (int i = 0; i < n; i++)
        {
            low = min(mat[i][0], low);
            high = max(mat[i][m - 1], high);
        }

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int cnt = 0;

            for (int i = 0; i < n; i++)
            {
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (cnt <= req)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
