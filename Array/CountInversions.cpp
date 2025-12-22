#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;
        int cnt = 0;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else {
                temp.push_back(arr[right++]);
                cnt += (mid - left + 1);
            }
        }

        while (left <= mid)
            temp.push_back(arr[left++]);

        while (right <= high)
            temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return 0;

        int mid = (low + high) / 2;
        int cnt = 0;

        cnt += mergeSort(arr, low, mid);

        cnt += mergeSort(arr, mid + 1, high);

        cnt += merge(arr, low, mid, high);

        return cnt;
    }
    int inversionCount(vector<int> &arr)
    {
        // Code Here
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};
