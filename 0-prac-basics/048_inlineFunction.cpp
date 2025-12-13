#include <iostream>
using namespace std;

inline int getMax(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int a = 3, b = 5;

    cout << getMax(a, b) << endl;

    a += 5;

    cout << getMax(a, b) << endl;

    return 0;
}