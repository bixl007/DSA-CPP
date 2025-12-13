#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(string &num, int target, vector<string> &ans, int idx, long long curr, long long last, string exp) {
        if(idx == num.size()) {
            if(curr == target) {
                ans.push_back(exp);
            }
            return;
        }
        
        for (int i = idx; i < num.size(); i++)
        {
            if(i > idx && num[idx] == '0')
                return ;

            string currNum = num.substr(idx, i - idx + 1);
            long long currVal = stoll(currNum);

            if(idx == 0)
                solve(num, target, ans, i + 1, currVal, currVal, currNum);
            else {
                solve(num, target, ans, i + 1, curr + currVal, currVal, exp + "+" + currNum);
                solve(num, target, ans, i + 1, curr - currVal, -currVal, exp + "-" + currNum);
                solve(num, target, ans, i + 1, curr - last + last * currVal, last * currVal, exp + "*" + currNum);
            }
        }
        
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, ans, 0, 0, 0, "");
        return ans;
    }
};