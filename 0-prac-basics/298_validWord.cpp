#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string word)
    {
        if (word.size() < 3)
            return false;

        int vowel = 0, consonant = 0;
        string vowels = "AEIOUaeiou";

        for (auto w : word)
        {
            if (w == '@' || w == '#' || w == '$')
                return false;
            if (vowels.find(w) != string::npos)
                vowel++;
            else if (isalpha(w))
                consonant++;
        }

        return (vowel > 0 && consonant > 0);
    }
};
