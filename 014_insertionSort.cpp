#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    // int i, j;
    // for(int i = 1; i < n; i++){
    //     int temp = arr[i];
    //     for(j = i - 1; j >= 0; j--){
    //         if(arr[j] > temp){
    //             arr[j + 1] = arr[j];
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     arr[j+1] = temp;
    // }

    int i = 1;
    while (i < n)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
                break;
        }
        arr[j + 1] = temp;
        i++;
    }
}

void outputArray(int arr[], int size)
{
    cout << "The sorted elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);
    outputArray(arr, n);
    return 0;
}