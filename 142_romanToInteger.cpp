
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> mp {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int val = 0;
        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] < mp[s[i + 1]])
                val -= mp[s[i]];
            else
                val += mp[s[i]];
        }
        return val;
    }
};