#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int maxi = 0, res = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            maxi = max(arr[i], maxi);
            if (maxi == i)
                res++;
        }
        return res;
    }
};