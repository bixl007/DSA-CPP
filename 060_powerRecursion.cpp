#include <iostream>
using namespace std;

int power(int n, int pow){
    if(pow == 0) return 1;

    if(pow == 1) return n;

    int ans = power(n, pow/2);

    if(pow % 2 == 0) return ans * ans;

    else return n * ans * ans;


}

int main(){
    int a , b;
    a = 2;
    b = 5;

    cout << power(a , b) << endl;
}