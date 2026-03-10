#include<bits/stdc++.h>
using namespace std;

void solve(int i, string &s, vector<string> &ans) {
    if(i >= s.length()) {
        ans.push_back(s);
        return ;
    }
    
    solve(i + 1, s, ans);
    s[i] = '1';
    solve(i + 2, s, ans);
    s[i] = '0';
}

vector<string> generateBinaryStrings(int n) {
    string s(n, '0');
    vector<string> ans;
    solve(0, s, ans);
    
    return ans;
}

int main() {
    int n = 4;
    vector<string> res = generateBinaryStrings(n);
    for (auto s: res) {
        cout << s << endl;
    }
    
    return 0;
}