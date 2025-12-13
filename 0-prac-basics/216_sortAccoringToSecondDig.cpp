#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {13, 2, 0, 5, 88}, lastDigit, ans;

    for (auto i : arr)
    {
        lastDigit.push_back(i % 10);
    }

    sort(lastDigit.begin(), lastDigit.end());

    for (int i = 0; i < lastDigit.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] % 10 == lastDigit[i])
            {
                ans.push_back(arr[j]);
                arr[j] = -1;
                break;
            }
        }
    }

    for (auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}