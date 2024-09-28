#include <iostream>
using namespace std;

struct node{
    int data;
    node * next;
};

node * front = NULL;
node * rear = NULL;

bool isEmpty(){
    return front == NULL;
}

void display(){
    if(isEmpty()){
        cout << "Stack is Empty." << endl;
        return;
    }

    node * temp = front;
    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}

void enqueue(){
    int value;
    cout << "Enter the value you want to enqueue : ";
    cin >> value;
    node * newnode = (node * ) malloc(sizeof(node));
    newnode -> data = value;
    newnode -> next = NULL;
    if(isEmpty()){
        front= rear = newnode;
    }else{
        rear -> next = newnode;
        rear = newnode;
    }
    cout << value << " is being enqueued to the queued." << endl;
    display();
}

void dequeue(){
    if(isEmpty()){
        cout << "Queue is empty. Cannot be dequeued." << endl;
        return;
    }

    cout << front -> data << " is being dequeued." << endl;
    node * temp = front;
    front = front -> next;
    if(front == NULL){
        rear = NULL;
    }
    free(temp);
    display();
}

int main(){
    int choice;
    while(true){
        cout << "\nMenu :\n" << endl; 
        cout << "1. ENQUEUE" << endl;
        cout << "2. DEQUEUE" << endl;
        cout << "3. DISPLAY" << endl;
        cout << "4. EXIT" << endl;
        cout << "Choose : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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