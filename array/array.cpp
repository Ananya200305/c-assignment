#include <iostream>
using namespace std;
int main(){
    int n;
    cout << " Enter the size : ";
    cin >> n;
    int array[n];
    for(int i = 0; i< n;i++){
        cout <<i+1 << " elements : ";
        cin >> array[i];
    }
    for(int i = 0 ; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    // int brr[n];
    // for(int i = 0; i < n;i++){
    //     brr[i] = array[n-i-1];
    // }
    // for(int i = 0 ; i < n; i++){
    //     cout << brr[i] << " ";
    // }
    int temp;
    for(int i = 0; i < n; i++){
        temp = array[i];
        array[i] = array[n-i-1];
        array[n-1-i]= temp;
    }
    for(int i = 0;i< n;i++){
        cout<<array[i];
    }
    return 0;
}