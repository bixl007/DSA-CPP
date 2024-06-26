#include <iostream>
using namespace std;

bool binarySearch(int arr[], int key, int start, int end)
{
    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
        return true;

    if (arr[mid] < key)
    {
        return binarySearch(arr, key, mid + 1, end);
    }
    else
    {

        return binarySearch(arr, key, start, mid - 1);
    }
}

int main()
{
    int arr[] = {1, 2, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int start = 0, end = size - 1;
    bool ans = binarySearch(arr, key, start, end);
    if (ans)
        cout << "key found!" << endl;
    else
        cout << "key not found!" << endl;

    return 0;
}