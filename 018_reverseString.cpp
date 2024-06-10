#include <iostream>
using namespace std;

void reverseString(char str[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
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
    reverseString(ch, len);
    cout << "The Reverse of the string is: " << ch << endl;
}