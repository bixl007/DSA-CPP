#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
    }
    return s;
}

int main()
{
    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = sum(arr, n);

    cout << "The sum of the elements of the array is : " << ans << endl;
}