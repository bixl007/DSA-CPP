#include <iostream>
using namespace std;

void selectionSort(int arr[], int start, int size)
{

    if (start >= size - 1)
        return;

    int minIndex = start;

    for (int i = start + 1; i < size; i++)
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }

    swap(arr[start], arr[minIndex]);

    selectionSort(arr, start + 1, size);
}

int main()
{
    int arr[5] = {5, 61, 8, 1, 2};
    selectionSort(arr, 0, 5);

    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
