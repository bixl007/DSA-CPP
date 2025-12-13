#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN;

        if(nums.size() == 1)
            return 0;

        for(int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - nums[i - 1];
            if(diff > maxi)
                maxi = diff;
        }

        return maxi;
    }
};