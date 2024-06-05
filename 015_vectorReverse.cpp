#include <iostream>
#include <vector>
using namespace std;

vector<int> reverseArray(vector<int> v)
{
    int end = v.size() - 1;
    int start = 0;

    while (start <= end)
    {
        swap(v[start], v[end]);
        start++;
        end--;
    } 
    return v;
}

void print(vector<int> v) {
    cout << "The elements of the array are: ";
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;

    int size = 0;
    cout << "Enter the size of the array: ";
    cin>>size;
    cout << endl;

        cout << "Enter the element: ";
    for(int i = 0; i < size; i++) {
        int num;
        cin>>num;
        arr.push_back(num);
    }

    vector<int> ans = reverseArray(arr);
    print(ans);
    
}
