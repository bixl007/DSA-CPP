#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int temp;
    string dfs(string pre, int n, int k)
    {
        if (n == 0)
            return pre;
        for (char c = 'a'; c <= 'c'; c++)
        {
            if (!pre.empty() && c == pre.back())
                continue;
            int cnt = (1 << (temp - pre.length() - 1));
            if (cnt >= k)
                return dfs(pre + c, n - 1, k);
            else
                k -= cnt;
        }
        return "";
    }

public:
    string getHappyString(int n, int k)
    {
        temp = n;
        return dfs("", n, k);
    }
};