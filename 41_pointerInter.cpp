#include <iostream>
using namespace std;

int main()
{
    int p = 5;
    int *ptr = &p;
    cout << "Value of original variable is :" << p << endl;
    cout << "Value of pointer is :" << *ptr << endl;
    cout << "Value of address of pointer is :" << ptr << endl;
    return 0;
}