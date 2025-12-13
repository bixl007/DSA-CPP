#include <bits/stdc++.h>
using namespace std;

// class Solution {
// private:
//     bool isSafe(int row, int col, vector<string> &comb, int n) {
//         int tempR = row, tempC = col;

//         while(row >= 0 && col >= 0) {
//             if(comb[row][col] == 'Q')
//                 return false;
//             row--;
//             col--;
//         }

//         row = tempR, col = tempC;
//         while(col >= 0) {
//             if(comb[row][col] == 'Q')
//                 return false;
//             col--;
//         }

//         row = tempR, col = tempC;
//         while(row < n && col >= 0) {
//             if(comb[row][col] == 'Q')
//                 return false;
//             row++;
//             col--;
//         }
//         return true;
//     }

//     void solve(int col, vector<string> &comb, vector<vector<string>> &ans, int n) {
//         if(col == n) {
//             ans.push_back(comb);
//             return ;
//         }

//         for(int i = 0; i < n; i++) {
//             if(isSafe(i, col, comb, n)) {
//                 comb[i][col] = 'Q';
//                 solve(col + 1, comb, ans, n);
//                 comb[i][col] = '.';
//             }
//         }
//     }
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> comb(n);
//         string st(n, '.');

//         for(int i = 0; i < n; i++) {
//             comb[i] = st;
//         }

//         vector<int> leftRow(n);
//         vector<int> lowDiag(2 * n - 1);
//         vector<int> lowDiag(2 * n - 1);

//         solve(0, comb, ans, n);
//         return ans;
//     }
// };

/****************************************************************************************************************************************/

class Solution
{
private:
    void solve(int col, vector<vector<string>> &ans, vector<string> &comb, vector<int> &left, vector<int> &lowDiag, vector<int> &upDiag, int n)
    {
        if (col == n)
        {
            ans.push_back(comb);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!left[i] && !lowDiag[col + i] && !upDiag[n - 1 + col - i])
            {
                comb[i][col] = 'Q';
                lowDiag[col + i] = 1;
                upDiag[n - 1 + col - i] = 1;
                left[i] = 1;
                solve(col + 1, ans, comb, left, lowDiag, upDiag, n);
                comb[i][col] = '.';
                lowDiag[col + i] = 0;
                upDiag[n - 1 + col - i] = 0;
                left[i] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> comb(n);
        string st(n, '.');

        for (int i = 0; i < n; i++)
        {
            comb[i] = st;
        }

        vector<int> left(n);
        vector<int> lowDiag(2 * n - 1);
        vector<int> upDiag(2 * n - 1);

        solve(0, ans, comb, left, lowDiag, upDiag, n);
        return ans;
    }
};