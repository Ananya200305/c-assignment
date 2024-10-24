#include <iostream>
using namespace std;

// maximum element in stack
#define MAX 10

int stack[MAX];
int TOS = -1; // top of stack

// empty
bool isEmpty(){
    return TOS == -1;
}

// full
bool isFull(){
    return TOS == MAX - 1;
}

// display
void display(){
    if(isEmpty()){
        cout << "Stack Underflown. No element can be popped." << endl;
        return;
    }
    for(int i = TOS; i >= 0; i--){
        cout << stack[i] << " ";
    }
}

// push
void push(){
    if(isFull()){
        cout << "Stack OverFlown. Nothing can be pushed."<<endl;
        display();
        return;
    }
    int value;
    cout << "Enter the value you want to push : ";
    cin >> value;
    

    stack[++TOS] = value;
    cout << value << " is pushed in stack." << endl;
    display();
}

// pop
void pop(){
    if(isEmpty()){
        cout << "Stack Underflown. No element can be popped.";
        return;
    }

    cout << stack[TOS] << " is been popped." << endl;
    TOS--;
    display();
}

// ppek
int peek(){
    if(isEmpty()){
        cout << "Stack is empty. Nothing to peek." << endl;
        return -1;
    }
    cout << "Top of Stack : " << stack[TOS] << endl;
    return stack[TOS];
}

int main (){
    int choice;
    while(true){
        cout << "\n Menu : \n" <<endl;
        cout << "1. PUSH " <<  endl;
        cout << "2. POP" << endl;
        cout << "3. PEEK" << endl;
        cout << "4. DISPLAY"<< endl;
        cout << "5. EXIT" << endl;
        cout << "Choose number : ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...";
                exit(0);
                break;
            default:
                cout << "Invalid Input.";
                break;
        }
    }
    return 0;
}