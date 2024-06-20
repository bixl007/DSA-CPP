#include <iostream>
using namespace std;

int main()
{
    int arr[5][5];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The 2-d array is: " << endl;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}