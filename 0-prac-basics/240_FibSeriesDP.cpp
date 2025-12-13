#include <bits/stdc++.h>
using namespace std;

// Top - Down => Memorisation
/*
int fib(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    cout << fib(n, dp) << endl;

    return 0;
}
*/

// Bottom - up => Tabulation
/*
int main()
{
    int n;
    cin >> n;

    // Step 1
    vector<int> dp(n + 1);

    // Step 2
    dp[1] = 1;
    dp[0] = 0;

    // Step 3
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;

    return 0;
}
*/

// Space Optimisation
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int prev1 = 1;
    int prev2 = 0;

    if (n == 0)
    {
        cout << prev2 << endl;
        return 0;
    }

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1 << endl;
    return 0;
}
