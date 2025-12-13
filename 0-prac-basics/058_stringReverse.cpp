#include <iostream>
using namespace std;


void reverseString(string &str, int i, int j){
    if(i > j) return;

    swap(str[i], str[j] );
    reverseString(str, ++i, --j);
}

int main(){
    string str = "Hello World";
    reverseString(str, 0, str.length() - 1);
    cout << str << endl;
}