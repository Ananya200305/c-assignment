#include <iostream>
using namespace std;
int main(){
    // char ch;
    // cout << "Enter an alphabets : ";
    // cin >> ch;
    // if(ch >= 'a' && ch <= 'z'){
    //     cout << "lowercase";
    // }else{
    //     cout << "uppercase";
    // }
    // int n;
    // cout << "Enter a number : ";
    // cin >> n;
    // int sum = 0;
    // for(int i = 1; i <= n ; i++){
    //     sum = sum + i;
    // }
    // cout << sum;
    // int n;
    // cout << "Enter the number : ";
    // cin >> n;
    // int sum = 0;
    // for(int i = 1; i <= n ; i += 2){
    //     sum = sum + i;
    // }
    // cout << sum;
    int n;
    cout << "Enter the number : ";
    cin >> n;
    for (int i = 2; i < n; i++){
        if(n%i == 0){
            cout << "It is not prime.";
        }else{
            cout << "It is prime.";
        }
    }
    return 0;
}