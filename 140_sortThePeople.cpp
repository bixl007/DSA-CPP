#include <map>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::vector<std::string> sortPeople(std::vector<std::string> &names, std::vector<int> &heights)
    {
        std::map<int, std::string> strMap;
        std::vector<std::string> ans;

        for (int i = 0; i < names.size(); i++)
        {
            strMap[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end());

        for (int i = names.size() - 1; i >= 0; i--)
        {
            ans.push_back(strMap[heights[i]]);
        }

        return ans;
    }
};