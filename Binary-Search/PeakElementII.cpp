#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxi(vector<vector<int>> &mat, int n, int col)
    {
        int maxi = -1;
        int idx = -1;

        for (int i = 0; i < n; i++)
        {
            if (mat[i][col] > maxi)
            {
                maxi = mat[i][col];
                idx = i;
            }
        }

        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int maxi = findMaxi(mat, n, mid);

            int left = mid - 1 >= 0 ? mat[maxi][mid - 1] : -1;
            int right = mid + 1 <= m ? mat[maxi][mid + 1] : -1;

            if (mat[maxi][mid] > left && mat[maxi][mid] > right)
                return {maxi, mid};
            if (left > mat[maxi][mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return {-1, -1};
    }
};