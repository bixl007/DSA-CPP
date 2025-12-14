#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> seats;

        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S')
                seats.push_back(i);
        }

        int n = seats.size();

        if (n == 0 || n & 1)
            return 0;

        long long res = 1;
        long long MOD = 1e9 + 7;

        for (int i = 2; i < n; i += 2) {
            long long diff = seats[i] - seats[i - 1];
            res = (res * diff) % MOD;
        }
        return res;
    }
};