#include <iostream>
using namespace std;

int main()
{
    int i = 5;
    int &j = i;
    cout << "The Value of i is: " << i << endl;
    cout << "The value of j is: " << j << endl;
    i++;
    j++;
    cout << "The Value of i is: " << i << endl;
    cout << "The value of j is: " << j << endl;
}