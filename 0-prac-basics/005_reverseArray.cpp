#include <iostream>
using namespace std;

void reverseArray(int arr[], int size)
{
    int end = size - 1;
    int start = 0;

    while (start != end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter the size: ";
    cin >> size;
    cout << endl;

    int arr[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    reverseArray(arr, size);
}
