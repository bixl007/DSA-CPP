#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s]; // Pivot is the first element
    int i = s + 1;      // Start from the element next to pivot
    int j = e;          // Start from the last element

    while (i <= j)
    {
        // Increment i until we find an element greater than the pivot
        while (i <= e && arr[i] <= pivot)
        {
            i++;
        }

        // Decrement j until we find an element smaller than the pivot
        while (j >= s && arr[j] > pivot)
        {
            j--;
        }

        // Swap the elements at i and j if i is still less than j
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    // Place the pivot in its correct position
    swap(arr[s], arr[j]);
    return j; // Return the index of the pivot
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int p = partition(arr, s, e);

    // Left Part
    quickSort(arr, s, p - 1);
    // Right Part
    quickSort(arr, p + 1, e);
}

int main()
{

    int arr[10] = {7, 1, 2, 5, 4, 9, 6, 3, 4, 2};
    int n = 10;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}