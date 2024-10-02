#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int counter = 1;
        unordered_map<int, int> parity;
        set<int> st;
        vector<int> ans(arr.size(), 0);

        for (auto i : arr)
        {
            st.insert(i);
        }

        for (auto i : st)
        {
            if (parity[i] == 0)
            {
                parity[i] = counter++;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            ans[i] = parity[arr[i]];
        }

        return ans;
    }
};