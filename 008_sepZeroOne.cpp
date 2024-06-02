#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << "The elements are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int zeroOne(int arr[], int size)
{
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        if (arr[i] == 0)
        {
            i++;
        }
        else if (arr[j] == 1)
        {
            j--;
        }
        else
        {
            swap(arr[i], arr[j]);
        }
    }
    return 0;
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
    zeroOne(arr, n);
    printArray(arr, n);

    return 0;
}
