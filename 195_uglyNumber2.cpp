#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int nthUglyNumber(int n)
    {
        vector<int> arr(n + 1);
        arr[1] = 1;
        int a = 1, b = 1, c = 1;

        for (int i = 2; i <= n; i++)
        {
            int ind1 = arr[a] * 2;
            int ind2 = arr[b] * 3;
            int ind3 = arr[c] * 5;
            int num = min({ind1, ind2, ind3});
            arr[i] = num;
            if (num == ind1)
                a++;
            if (num == ind2)
                b++;
            if (num == ind3)
                c++;
        }
        return arr[n];
    }
};