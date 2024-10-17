#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checkPrime(int n)
    {
        if (n == 0 || n == 1)
            return 0;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }

public:
    int diagonalPrime(vector<vector<int>> &nums)
    {
        int x = 0, maxi = INT_MIN;
        vector<int> ans;
        int s1 = nums.size();
        int s2 = nums[0].size();

        for (int i = 0; i < s1; i++)
        {
            int val1 = nums[i][x];
            int val2 = nums[i][s2 - x - 1];
            if (checkPrime(val1))
                maxi = max(maxi, val1);
            if (checkPrime(val2))
                maxi = max(maxi, val2);
            x++;
        }

        if (maxi <= 0)
            return 0;

        return maxi;
    }
};