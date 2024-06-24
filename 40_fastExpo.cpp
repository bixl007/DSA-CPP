#include <iostream>
using namespace std;

int fastExpo(int a, int b)
{
    int res = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
        }
        b = b >> 1; // b >> 1 means it divides b by 2
        a = a * a;
    }
    return res;
}

int main()
{
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    int ans = fastExpo(a, b);
    cout << "Answer is : " << ans << endl;
}