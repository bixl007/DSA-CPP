#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct TrieNode
    {
        TrieNode *children[26];
        bool isEnd;
        TrieNode()
        {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode *root;

    void insert(string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

    void dfs(TrieNode *node, string &current, string &result)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] && node->children[i]->isEnd)
            {
                current.push_back(i + 'a');
                if (current.length() > result.length())
                {
                    result = current;
                }
                dfs(node->children[i], current, result);
                current.pop_back();
            }
        }
    }

public:
    string longestValidWord(vector<string> &words)
    {
        root = new TrieNode();
        string res = "";
        string curr = "";

        for (auto i : words)
        {
            insert(i);
        }

        dfs(root, res, curr);
        return res;
    }
};
