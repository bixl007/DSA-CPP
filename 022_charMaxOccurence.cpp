#include <iostream>
using namespace std;

char maxOccurrence(string s)
{
    int arr[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else
        {
            number = ch - 'A';
        }
        arr[number]++;
    }
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }

    char answer = 'a' + ans;
    return answer;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "The character with maximum occurrence is : " << maxOccurrence(s) << endl;
}