// leetcode 48. Rotate Image

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();

        

        for(int i = 0; i < m; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }

        }
        for(int i = 0; i < m; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};