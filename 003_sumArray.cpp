#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of your array: ";
    cin >> size;
    int arr[size], sum = 0;

    cout << "Enter the elements of your array: ";

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "The sum of your array is: " << sum << endl;
}