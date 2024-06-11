#include <iostream>
using namespace std;

char toLower(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        ch = ch - 'A' + 'a';
    }
    return ch;
}

int main()
{
    cout << toLower('Z') << endl;
}