#include <iostream>
using namespace std;
int main(){
    int arr[10][10];
    int row;
    int column;
    int count = 0;
    cout << "Enter the row : ";
    cin >> row;
    cout << "Enter the column : ";
    cin >> column;
    if(column > 10 || row > 10 || column < 0 || row < 0){
        cout << "Invalid input. Enter between 0 to 10.";
    }

    cout << "Enter the matrix : " << endl;
    for(int i = 1;i <= row ; i++){
        for(int j = 1; j <= column ; j++){
            cout << "Enter the element for " << i << " " << j << " : " << endl;
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= row ; i++){
        for(int j = 1; j <= column ; j++){
            if(arr[i][j] != 0){
                count ++;
            }
        }
    }

    cout << "Enter the number of elements of an array : " << (row * column) << endl;
    cout << "Enter the number of non zero element in the array : " << count << endl;

    // sparse array representation 

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){
            cout << "Sparse Array : " << endl;
            cout << i << " " << j << " " << count << endl;
            
        }
    }
    return 0;
}