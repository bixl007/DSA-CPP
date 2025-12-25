#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long res = 0;
        int n = happiness.size();

        for(int i = 0; i < n && i < k; i++) {
            long long temp = happiness[i] - i;
            if(temp < 0)
                break;
            res += temp;
        }

        return res;
    }
};