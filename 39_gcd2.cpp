// GCD Euclidean Algorithm: modulo based approach

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    int ans = gcd(a, b);
    cout << "GCD of " << a << " and " << b << " is : " << ans << endl;
    return 0;
}