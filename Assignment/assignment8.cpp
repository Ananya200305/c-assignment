#include <iostream>
using namespace std;

#define MAX 10

int stack[MAX];
int TOS = -1;

bool isEmpty(){
    return TOS == -1;
}

bool isFull(){
    return TOS == MAX - 1;
}

void display(){
    if(isEmpty()){
        cout << "Stack is empty." << endl;
        return;
    }
    for(int i = TOS; i >= 0; i--){
        cout << stack[i] << " ";
    }
}

void push(){
    int value;
    cout << "Enter the value you want to push : ";
    cin >> value;
    if(isFull()){
        cout << "Stack OverFlown. " << value << " cannot be pushed."<<endl;
        display();
        return;
    }

    stack[++TOS] = value;
    cout << value << " is pushed in stack." << endl;
    display();
}

void pop(){
    if(isEmpty()){
        cout << "Stack Underflown. " << stack[TOS] << " cannot be popped.";
        return;
    }

    cout << stack[TOS] << " is been popped." << endl;
    TOS--;
    display();
}

int peep(){
    if(isEmpty()){
        cout << "Stack is empty." << endl;
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
        cout << "3. PEEP" << endl;
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
                peep();
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