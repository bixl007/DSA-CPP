#include <iostream>
using namespace std;

bool search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
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
    cout << "Enter the key: ";
    cin >> key;

    if (search(arr, size, key))
        cout << "True" << endl;
    else
        cout << "false" << endl;

    return 0;
}
