#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(vector<int> &stalls, int lim, int k) {
        int cnt = 1, last = stalls[0];

        for (int i = 1; i < stalls.size(); i++)
        {
            if(stalls[i] - last >= lim) {
                cnt++;
                last = stalls[i];
            }
            if(cnt >= k)
                return true;
        }
        return false;
        
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int low = 1, high = stalls[n - 1];
        
        while (low <= high) 
        {
            long long mid = low + (high - low) / 2;

            if(check(stalls, mid, k)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return high;
    }
};