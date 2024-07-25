#include <string>

class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (count == 0 && s[i] == ' ')
                count = 0;
            else
            {
                if (s[i] != ' ')
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};