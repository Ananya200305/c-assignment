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
    if(row > 10 || column > 10 || row <= 0 || column <= 0){
        cout << "Enter less than 10 or greater than 0.";
        return -1;
    }
    cout << "Enter the matrix : " << endl;
    for(int i = 1 ; i <= row ; i++){
        for(int j = 1; j <= column; j++){
            cout << "Element for " << i <<" "<< j << endl;
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){
            if(arr[i][j] != 0){
                count ++;
            }
        }
        cout << endl;
        }
        
    cout << "The number of elements in the array : " << (row*column) << endl;
    cout << "The number of non zero element in the array : " << count << endl;
    if(((row*column)/2 > count)){
        cout << "This is sparse array" << endl;
         cout << "Sparse array representation :" << endl;
         cout << row << " " << column << " " << count << endl;
         for(int i = 1; i <= row; i++){
            for(int j = 1; j <= column; j++){
                if(arr[i][j] != 0){
                    cout << i  << " " << j  << " " << arr[i][j] << endl;
            }
        }
    }
    } else{
        cout << "This is not a sparse array." << endl;
    }

   
    
    

    return 0;
}