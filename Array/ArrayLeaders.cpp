#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        int maxi = INT_MIN;
        vector<int> res;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] >= maxi) {
                res.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        
        reverse(res.begin(), res.end());

        return res;
    }
};