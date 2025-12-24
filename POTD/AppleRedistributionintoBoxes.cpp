#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int total = accumulate(apple.begin(), apple.end(), 0);

        int cnt = 0;
        sort(capacity.rbegin(), capacity.rend());
        for (int i = 0; i < capacity.size(); i++)
        {
            if (total && total <= capacity[i])
            {
                cnt++;
                return cnt;
            }
            else
            {
                total -= capacity[i];
                cnt++;
            }
        }

        return capacity.size();
    }
};