#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[2];
    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit))
            {
                maxi = maxi | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> offlineQueries;
        int q = queries.size();
        for (int i = 0; i < q; i++)
        {
            offlineQueries.push_back({queries[i][1], queries[i][0], i});
        }

        sort(offlineQueries.begin(), offlineQueries.end());

        vector<int> ans(q);
        Trie trie;
        int index = 0;
        int n = nums.size();

        for (int i = 0; i < q; i++)
        {
            int mi = offlineQueries[i][0];
            int xi = offlineQueries[i][1];
            int qIndex = offlineQueries[i][2];

            while (index < n && nums[index] <= mi)
            {
                trie.insert(nums[index]);
                index++;
            }

            if (index == 0)
            {
                ans[qIndex] = -1;
            }
            else
            {
                ans[qIndex] = trie.getMax(xi);
            }
        }

        return ans;
    }
};