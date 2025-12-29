#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct TrieNode
    {
        TrieNode *children[26];
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    int countSubs(string &s)
    {
        // code here
        TrieNode *node = new TrieNode();
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            TrieNode *temp = node;
            for (int j = i; j < n; j++)
            {
                int idx = s[j] - 'a';
                if (!temp->children[idx])
                {
                    temp->children[idx] = new TrieNode();
                    cnt++;
                }
                temp = temp->children[idx];
            }
        }
        return cnt;
    }
};