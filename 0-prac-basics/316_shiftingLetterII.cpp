#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size();
        vector<int> shift(n + 1, 0);

        for (auto &i : shifts)
        {
            int start = i[0], end = i[1], direction = i[2];
            shift[start] += (direction == 1 ? 1 : -1);
            shift[end + 1] -= (direction == 1 ? 1 : -1);
        }

        int currentShift = 0;
        for (int i = 0; i < n; ++i)
        {
            currentShift += shift[i];
            shift[i] = currentShift;
        }

        for (int i = 0; i < n; ++i)
        {
            int netShift = (shift[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }

        return s;
    }
};