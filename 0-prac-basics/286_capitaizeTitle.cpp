#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        vector<string> st;
        string temp = "";

        for (int i = 0; i < title.length(); i++)
        {
            if (title[i] == ' ')
            {
                st.push_back(temp);
                temp = "";
            }
            else
            {
                temp.push_back(tolower(title[i]));
            }
            if (i == title.length() - 1)
            {
                st.push_back(temp);
                temp = "";
            }
        }

        for (auto &i : st)
        {
            if (i.length() > 2)
            {
                i[0] = toupper(i[0]);
            }
            temp += i + " ";
        }

        temp.pop_back();

        return temp;
    }
};