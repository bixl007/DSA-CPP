#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSetBits(int n)
    {
        int count = 0;
        while (n)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    int minimizeXor(int num1, int num2)
    {
        int bits = countSetBits(num2);
        int result = 0;
        for (int i = 31; i >= 0 && bits > 0; i--)
        {
            if (num1 & (1 << i))
            {
                result |= (1 << i);
                bits--;
            }
        }
        for (int i = 0; i < 32 && bits > 0; i++)
        {
            if (!(result & (1 << i)))
            {
                result |= (1 << i);
                bits--;
            }
        }
        return result;
    }
};