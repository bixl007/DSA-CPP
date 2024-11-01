#include <iostream>
using namespace std;

// Recursive
class Solution
{
public:
    int solve(int n)
    {
        if (n == 0)
        {
            return 0;
        }

        int ans = n;

        for (int i = 1; i * i <= n; i++)
        {
            int temp = i * i;
            ans = min(ans, 1 + solve(n - temp));
        }
        return ans;
    }

    int MinSquares(int n)
    {
        return solve(n);
    }
};