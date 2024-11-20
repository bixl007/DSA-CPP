#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        int sumLeft = 0;
        int sumRight = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sumRight += nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                sumLeft = 0;
            else
                sumLeft += nums[i - 1];

            sumRight -= nums[i];

            if (sumLeft == sumRight)
                return i;
        }
        return -1;
    }
};