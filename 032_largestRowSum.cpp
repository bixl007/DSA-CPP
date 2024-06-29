#include <iostream>
#include <climits>
using namespace std;

void maxSum(int arr[][2], int n, int m)
{
    int s = 0, index = 0;
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int j = 0; j < m; j++)
        {
            s += arr[i][j];
        }
        cout << s << endl;
        if(s > max){
            max = s;
            index = i;
        }

    }
    cout << "The largest sum is: " << s << " and the index is: " << index << endl;
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
    maxSum(arr, 2, 2);
}