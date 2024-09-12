#include <iostream>
using namespace std;
void addFront(int arr,int size){
    if(size >= 10){
        cout << "Array is full.";
    }
    for(int i = size; i > 0; i--){
        arr[i+1] = arr[i];
    }
}
int main(){
    int arr[10];
    int size;
    return 0;
}