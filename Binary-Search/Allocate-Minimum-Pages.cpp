#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findStud(vector<int> &arr, int lim) {
        int stud = 1;
        long long maxi = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if(maxi + arr[i] <= lim) {
                maxi += arr[i];
            }
            else {
                maxi = arr[i];
                stud++;
            }
        }

        return stud;
        
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size())
            return -1;
        int low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        
        while (low <= high) 
        {
            long long mid = low + (high - low) / 2;
            int stud = findStud(arr, mid);

            if(stud > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
        
    }
};