#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0)
            return ans;
        if (k > 0)
        {
            int sum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
            ans[0] = sum;
            for (int i = 1, j = k + 1; i < n; j++, i++)
            {
                sum += -code[i] + code[j % n];
                ans[i] = sum;
            }
            return ans;
        }
        k = -k;
        int sum = accumulate(code.end() - k, code.end(), 0);
        ans[0] = sum;
        for (int i = 0, j = n - k; i < n - 1; i++, j++)
        {
            sum += -code[j % n] + code[i];
            ans[i + 1] = sum;
        }
        return ans;
    }
};