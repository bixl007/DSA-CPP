#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{
    if (size == 0)
        return false;

    if (arr[0] == key)
        return true;

    return linearSearch(arr + 1, size - 1, key);
}

int main()
{
    int arr[] = {1, 2, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    bool ans = linearSearch(arr, size, key);
    if (ans)
        cout << "key found!" << endl;
    else
        cout << "key not found!" << endl;

    return 0;
}