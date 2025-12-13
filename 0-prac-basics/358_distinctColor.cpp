#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball, color;
        vector<int> ans;
        int dist = 0;

        for(auto &i : queries) {
            int pos = i[0], c = i[1];
            if(ball.count(pos))
                if(--color[ball[pos]] == 0)
                    dist--;
            ball[pos] = c;
            if(++color[c] == 1)
                dist++;
            ans.push_back(dist);
        }
        return ans;
    }
};