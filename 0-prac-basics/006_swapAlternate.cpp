#include <iostream>
using namespace std;

void swapElement(int arr[], int size)
{
    int i = 0;
    int j = 1;

    while (i < size && j < size)
    {
        swap(arr[i], arr[j]);
        i+=2;
        j+=2;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int size, key;
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
    swapElement(arr, size);
}
