#include <iostream>
using namespace std;
int main(){
    int arr[10][10];
    int n;
    int n1;
    int count = 0;
    cout << "Enter the row : ";
    cin >> n;
    if(n > 10){
        cout << "Enter less than 10.";
        // return;
    }
    cout << "Enter the column : ";
    cin >> n1;
    if(n1 > 10){
        cout << "Enter less than 10.";
        // return;
    }
    cout << "Enter the matrix : " << endl;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n1; j++){
            cout << "Element for " << i << j << endl;
            cin >> arr[i][j];
        }
    }
    
    cout << "The matrix is : " << endl;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n1; j++){
            cout << arr[i][j] << " ";
            if(arr[i][j] == 0){
                count ++;
            }
        }
        cout << endl;
        }
    

    cout << "The number of zero in array : " << count << endl;
    if(((n*n1)/4 < count)){
        cout << "This is sparse array";
    } else{
        cout << "This is not a sparse array.";
    }

    

    return 0;
}