#include <iostream>
using namespace std;

int x = 10; // Global variable

void printVal()
{
    cout << x << endl;
}

int main()
{
    printVal();
    cout << "Value of global variable: " << x << endl;
}
