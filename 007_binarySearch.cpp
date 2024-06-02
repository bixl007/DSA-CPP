#include <iostream>
using namespace std;

int binSearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << endl;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    int key;
    cout << "Enter the key: ";
    cin >> key;
    cout << endl;

    cout << "The number was found at: " << binSearch(arr, n, key) + 1 << " position" << endl;

    return 0;
}
