#include <iostream>
using namespace std;
void traverse(int number[]){
    for (int i = 0 ; i < 20; i++){
        cout << number[i] << " ";
        }
}

int insert(int number[],int position,int num){
    cout << "Enter the number you want to insert : "; 
    cin >> num;
    cout << "Enter the position you want to insert : ";
    cin >> position;
    for(int i = 20 ; i >= position ; i-- ){
        number[i+1] = number[i];
    }
    number[position] = num;
    cout << "New Array" << endl;
    for (int i = 0; i < 20 ; i++){
        cout << number[i] << " ";
    }

    return 0;
}

void delete1(int number[],int del){
    cout << "Enter the postion you want to delete : ";
    cin >> del;
    for(int i = del; i < 20 ; i++){
        number[i] = number[i+1];
    }
    cout << "New Array : ";
    for(int i = 0 ; i < 20; i++){
        cout << number[i] << " ";
    }
}

int search(int number[],int key){
    cout << "Enter the number you want to search : ";
    cin >> key;
    for (int i = 0; i < 20 ; i++){
        if(number[i] == key){
            return i;
        }
    }return -1;
}

void sort(int number[], int temp){
    for(int i = 0; i < 19 ; i++){
        for(int j = 0 ; j < 19 - i ; j++){
            if(number[j] > number [j+1]){
                temp = number[j+1];
                number[j+1] = number[j];
                number[j] = temp;
            }
        }
    }
    cout << "New Array : ";
    for (int i = 0; i < 20 ; i++){
        cout << number[i] << " ";
    }
}





int main(){
    int number[20] = {2,5,6,4,9,1,3,8,7};
    int position;
    int num;
    int key;
    int del;
    int temp;
    cout << "You can choose the following operation that you can perfom on array NUMBER : " << endl;
    cout << "1. Choose 1 to SEE the array. " << endl;
    cout << "2. Choose 2 to INSERT A NUMBER the array. " << endl;
    cout << "3. Choose 3 to DELETE A NUMBER the array. " << endl;
    cout << "4. Choose 4 to SEARCH A NUMBER the array. " << endl;
    cout << "5. Choose 5 to SORT the array. " << endl;
    cout << "6. Choose 6 to EXIT. " << endl;
    while(true){int choose;
    cout << "\n Choose number : ";
    cin >> choose;
    if(choose == 1){
        traverse(number);
    }else if(choose == 2){
        insert(number, position,num);
    }else if(choose == 3){
        delete1(number,del);
    }
    else if(choose == 4){
        int index = search(number,key);
        if(index != -1){
            cout << "The number is found at " << index+1;
        }else{
            cout << "The number is not found";
        }
    }else if(choose == 5){
        sort(number,temp);
    }else if(choose == 6){
        cout << "You exit !";
        break;
        
    }else{
        cout << "Enter a valid number.";
    }
   
    }
    return 0;
}
