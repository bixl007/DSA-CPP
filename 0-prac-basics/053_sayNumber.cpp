#include <iostream>
using namespace std;

void sayName(int n, string arr[])
{
    if (n == 0)
        return;

    int digit = n % 10;
    n = n / 10;

    sayName(n, arr);

    cout << arr[digit] << endl;
}

int main()
{
    int n;
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    cout << "Enter the number: " << endl;
    cin >> n;
    cout << endl;
    sayName(n, arr);
}