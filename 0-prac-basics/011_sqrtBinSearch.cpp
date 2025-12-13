#include <iostream>
using namespace std;

int floorSqrt(int n)
{
    int start = 0;
    int end = n;
    long long int mid = start + (end - start) / 2 , ans = -1;

    while(start <= end){
        long long int sq = mid * mid;

        if(sq == n){
            return mid;
        }
        else if (sq < n){
            ans = mid;
            start = mid + 1;
        }
        else{
            
            end = mid - 1;
        }
        mid = start + (end - start) / 2;

    }
    return ans;

}

double precision(int n, int precision,int tempSol){
    double ans = tempSol;
    double factor = 1;
    for (int i = 0; i < precision; i++)
    {   
        factor /= 10;
        for (double j = ans; j*j<n; j+=factor)
        {
            ans = j;
        }
        
    }
    return ans;
    
}


int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int tempSol = floorSqrt(n);
    cout << "Floor square root of " << n << " is " << precision(n, 3, tempSol) << endl;
}