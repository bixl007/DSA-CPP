#include <iostream>
using namespace std;

// int count(int n)
// {
//     if (n == 0)
//         return 0;

//     cout << n << endl;

//     return count(n - 1);
// }

void count(int n)
{
    if (n == 0)
        return;

    count(n - 1);

    cout << n << endl;
}

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    cout << endl;
    count(n);
}
