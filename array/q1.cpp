#include <iostream>
using namespace std;
int main(){
    int array[4] = {2,7,11,15};
    int target = 9;
    for(int i = 0; i < 4; i++){
        for(int j = i+1; j <4; j++){
            if(array[i] + array[j] == target){
                cout << i << " " << j << endl;;
            }
        }
    }
}