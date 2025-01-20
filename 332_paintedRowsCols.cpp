#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int row = mat.size();
        int col = mat[0].size();
        unordered_map<int, pair<int, int>> pos;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                pos[mat[i][j]] = {i, j};

        vector<int> rowCount(row, 0);
        vector<int> colCount(col, 0);

        for (int i = 0; i < arr.size(); i++)
        {
            auto [r, c] = pos[arr[i]];
            rowCount[r]++;
            colCount[c]++;
            if (rowCount[r] == col || colCount[c] == row)
                return i;
        }
        return arr.size() - 1;
    }
};