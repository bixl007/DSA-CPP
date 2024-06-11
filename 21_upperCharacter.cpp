#include <iostream>
using namespace std;

char toUpper(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch;
    }
    else
    {
        ch = ch - 'a' + 'A';
    }
    return ch;
}

int main()
{
    cout << toUpper('z') << endl;
}