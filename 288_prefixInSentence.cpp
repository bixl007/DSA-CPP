#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        string ans = "";
        int counter = 1;

        for (int i = 0; i < sentence.size(); i++)
        {
            if (isalpha(sentence[i]))
                ans += sentence[i];

            else
            {
                ans = "";
                counter++;
            }

            if (ans.substr(0, searchWord.size()) == searchWord)
                return counter;
        }
        return -1;
    }
};