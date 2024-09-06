#include <iostream>
using namespace std;

int main(){

    int a;
    a = 12;

    cout << "Size of a " << sizeof(a) << endl;

    float b;
    b = 12.67;

    cout << "Size of b " << sizeof(b) << endl;

    char c;
    cout << "Size of c " << sizeof(c) << endl;

    short int e;
    cout << "Size of e " << sizeof(e) << endl;

    long int f;
    cout << "Size of f " << sizeof(f) << endl;
    return 0;
}