#include <iostream>
using namespace std;

void mergeArray(int arr1[], int n, int arr2[2], int m, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i <= j)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
}

void print(int ans[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};

    int arr3[10];

    mergeArray(arr1, 5, arr2, 5, arr3);

    print(arr3, 10);
    return 0;
}