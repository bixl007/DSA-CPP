#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int curr = nums[0], maxi = curr;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) {
                curr += nums[i];
            }
            else {
                curr = nums[i];
            }
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};