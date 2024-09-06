#include <iostream>
using namespace std;


int main(){

    // for(int i = 1; i <= 5 ; i++){
    //     cout << i << " ";
    // }

    // int i = 1;


    // while(i <= 5){
    //     cout << i << " ";
    //     i++;
    // }

    // do {
    //     cout << i << " ";
    //     i++;
    // }while(i <= 5);

    // int n;
    // cin >> n;
    // int sum = 0;
    
    // for (int counter = 1 ; counter <= n ; counter ++){
    //     sum = counter + sum;
    // }
    // cout << sum;


    // int n ;
    // cin >> n;

    // for(int counter = 1; counter <= 10 ; counter ++){
    //     cout << n*counter << " " << endl;;
    // }
    int number[] = {3,1,2};
    int key = 2;

    for (int i = 0; i < 3 ; i++){
        if(number[i] == key){
            cout << i;
            break;
        }
    }


    

    return 0;
}