#include <iostream>
using namespace std;

int sumArray(int arr[], int size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return arr[0];

    return arr[0] + sumArray(arr + 1, size - 1);
}

int main()
{
    int arr[] = {1, 2, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = sumArray(arr, size);

    cout << "Sum is " << ans << endl;

    return 0;
}