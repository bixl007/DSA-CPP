#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        if (sentence.empty())
            return true;

        vector<string> words;
        string word;

        for (char c : sentence)
        {
            if (c == ' ')
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word.clear();
                }
            }
            else
            {
                word += c;
            }
        }
        if (!word.empty())
        {
            words.push_back(word);
        }

        if (words.size() == 1)
        {
            return words[0][0] == words[0][words[0].size() - 1];
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            if (words[i][words[i].size() - 1] != words[i + 1][0])
            {
                return false;
            }
        }

        return words[words.size() - 1][words[words.size() - 1].size() - 1] ==
               words[0][0];
    }
};