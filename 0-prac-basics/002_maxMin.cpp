#include <iostream>
using namespace std;

void maxMin(int arr[], int size)
{
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++){
        max = max >= arr[i]? max: arr[i];
        min = min <= arr[i]? min: arr[i];
    }
    cout << "The largest element in the array is "<< max << endl;
    cout << "The smallest element in the array is "<< min << endl;
}

int main()
{
    int size;
    cout << "Enter the size of your array: ";
    cin >> size;
    int arr[size];

    cout << "Enter the elements of your array: ";

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    maxMin(arr, size);
}