#include <iostream>
using namespace std;

void insertionSort(int arr[], int start, int size)
{
    if (start >= size)
        return;

    int temp = arr[start], i;

    for (i = start - 1; i >= 0; i--)
    {
        if (arr[i] > temp)
            arr[i + 1] = arr[i];

        else
            break;
    }
    arr[i + 1] = temp;

    insertionSort(arr, start + 1, size);
}

int main()
{
    int arr[5] = {5, 61, 8, 1, 2};
    insertionSort(arr, 1, 5);

    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
