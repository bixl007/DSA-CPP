// This code represent my solution for the leetcode question of 567. Permutation in String

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int l, r, n1 = s1.size(), n2 = s2.size();
        l = r = 0;
        if (n1 > n2)
            return false;

        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for (auto &i : s1)
        {
            v1[i - 'a']++;
        }

        while (r < n1)
        {
            v2[s2[r] - 'a']++;
            r++;
        }
        while (r < n2)
        {
            if (v1 == v2)
            {
                return true;
            }
            else
            {
                v2[s2[l] - 'a']--;
                l++;
                v2[s2[r] - 'a']++;
                r++;
            }
        }
        if (v1 == v2)
        {
            return true;
        }
        return false;
    }
};