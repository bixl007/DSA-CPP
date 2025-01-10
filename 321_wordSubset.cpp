#include <bits/stdc++.h>
using namespace std;

// Hashmap approach
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        map<char, int> mp;
        for (auto it : words2)
        {
            map<char, int> temp;
            for (int i = 0; i < it.size(); i++)
            {
                temp[it[i]]++;
            }
            for (auto itr : temp)
            {
                char c = itr.first;
                int freq = itr.second;
                mp[c] = max(mp[c], temp[c]);
            }
        }
        vector<string> ans;
        for (auto it : words1)
        {
            map<char, int> mp2;
            for (auto i : it)
            {
                mp2[i]++;
            }
            bool flag = 1;
            for (auto itr : mp)
            {
                char c = itr.first;
                int freq = itr.second;
                if (mp2[c] >= freq)
                {
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                ans.push_back(it);
        }
        return ans;
    }
};

// Optimal Approach
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
        vector<string> ans;
        vector<int> countB(26);
        for (const string &b : B)
        {
            vector<int> temp = counter(b);
            for (int i = 0; i < 26; ++i)
                countB[i] = max(countB[i], temp[i]);
        }
        for (const string &a : A)
        {
            if (isUniversal(counter(a), countB))
                ans.push_back(a);
        }
        return ans;
    }

private:
    vector<int> counter(const string &s)
    {
        vector<int> count(26);
        for (char c : s)
            ++count[c - 'a'];
        return count;
    }
    bool isUniversal(vector<int> countA, vector<int> &countB)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (countA[i] < countB[i])
                return false;
        }
        return true;
    }
};