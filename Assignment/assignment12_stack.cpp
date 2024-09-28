#include <iostream>
using namespace std;

struct node{
    int data;
    node * next;
};

node * tos = NULL;

bool isEmpty(){
    return tos == NULL;
}

void display(){
    if(isEmpty()){
        cout << "Stack is Empty." << endl;
        return;
    }

    node * temp = tos;
    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}

void push(){
    int value;
    cout << "Enter the value you want to push : ";
    cin >> value;
    node * newnode = (node * ) malloc(sizeof(node));
    newnode -> data = value;
    newnode -> next = tos;
    tos = newnode;
    cout << value << " is being pushed to the stack." << endl;
    display();
}

void pop(){
    if(isEmpty()){
        cout << "Stack is empty. Cannot be popped." << endl;
        return;
    }

    cout << tos -> data << " is being popped." << endl;
    node * temp = tos;
    tos = tos -> next;
    free(temp);
    display();
}

int main(){
    int choice;
    while(true){
        cout << "\nMenu :\n" << endl; 
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. DISPLAY" << endl;
        cout << "4. EXIT" << endl;
        cout << "Choose : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting....." << endl;
            exit(0);
        default:
            cout << "Invalid Input." << endl;
            break;
        }
    }
    return 0;
}