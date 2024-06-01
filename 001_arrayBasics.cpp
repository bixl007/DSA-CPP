#include <iostream>
using namespace std;

void outputArray(int arr[], int size){
    cout << "The elements are: "<< endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int main(){
    int size;
    cout << "Enter the size of your array: ";
    cin >> size;
    int arr[size];
    
    cout << "Enter the elements of your array: ";


    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    outputArray(arr,size);


}