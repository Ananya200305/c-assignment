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
        cout << "Queue is empty." << endl;
        return;
    }

    node * temp = front;
    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    }while(temp != front);
}

void enqueue(){
    int value;
    cout << "Enter the value you want to enqueue : ";
    cin >> value;
    
    node * newnode = (node *) malloc(sizeof(node));
    newnode -> data = value;

    if(isEmpty()){
        front = newnode;
        rear = newnode;
        newnode -> next = newnode;
    }else{
        rear -> next = newnode;
        rear = newnode ;
        rear -> next = front;
    }
    cout << value << " is being enqueued in the queue." << endl;
    display();
}

void dequeue(){
    if(isEmpty()){
        cout << "Queue is empty. Cannot be dequeued." << endl;
        return;
    }
    if(front == rear){
        cout << front -> data << " is being dequeued from the queue." << endl;
        free(front);
        front = rear = NULL;
    }else{
        node * temp = front;
        cout << front -> data << " is being dequeued from in the queue." << endl;
        front = front -> next;
        rear -> next = front;
        free(temp);
    }
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