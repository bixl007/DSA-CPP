#include <iostream>
using namespace std;

char toLower(char ch)
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
    cout << toLower('z') << endl;
}