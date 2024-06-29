#include <iostream>
using namespace std;

bool isFound(int arr[][2], int n, int m, int key)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == key)
                return true;
        }
    }
    return false;
}

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

    int ans = isFound(arr, 2, 2, 6);
    if (ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}