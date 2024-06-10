#include <iostream>
using namespace std;

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
    cout << "The Length of the string is: " << countLength(ch) << endl;
}