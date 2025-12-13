#include <iostream>
using namespace std;

int main()
{
    int arr[2][2] = {{4, 8}, {8, 6}};

    cout << "The 2-d array is: " << endl;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}