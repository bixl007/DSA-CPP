#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, x = 0;
        for(int i = 0; i < mat.size(); i++) {
            int val1 = mat[i][x];
            int val2 = mat[i][mat[0].size() - x - 1];
            if(x == (mat[0].size() - x - 1)) {
                sum += val1;
            }
            else {
                sum += val1 + val2;
            }
            x++;
        }
        return sum;
    }
};