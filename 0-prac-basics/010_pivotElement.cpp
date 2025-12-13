#include <iostream>
using namespace std;

void printArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int pivot(int arr[], int size){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;

    while (start < end)
    {
        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
    
}

int main(){
int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
    printArr(arr, size);

    cout << "The Pivot is: " << pivot(arr, size);
    cout<<endl;

    return 0;
}