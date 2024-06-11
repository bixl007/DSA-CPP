#include <iostream>
using namespace std;

int palindromeString(char str[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
        else
        {
            i++;
            j--;
        }
    }
    return 1;
}

char toLower(char ch){
    if(ch>='a' && ch <='z'){
        return ch;
    }
    else{
        ch = ch - 'A' + 'a';
    }
    return ch;
}

int countLength(string str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{

    char ch[100];

    cout << "Enter your String: ";
    cin >> ch;
    cout << "Your String is: " << ch << endl;
    int len = countLength(ch);
    int ans = palindromeString(ch, countLength(ch));
    if (ans == 1)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome!" << endl;
    }
}