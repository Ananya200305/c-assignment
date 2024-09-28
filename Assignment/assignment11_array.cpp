#include <iostream>
using namespace std;

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

bool isEmpty(){
    return front == -1;
}

bool isFull(){
    return (rear + 1) % MAX == front;
}

void display(){
    if(isEmpty()){
        cout << "Queue is empty." << endl;
    }
    int i = front;
    do {
        cout << queue[i] << " ";
        i = (i+1) % MAX;
    }while(i != (rear + 1) % MAX);
}

void enqueue(){
    int value;
    cout << "Enter the value you want to enqueue : ";
    cin >> value;
    if(isFull()){
        cout << "Queue is Full. " << value << " cannot be enqueued." <<endl;
        return;
    }
    if(isEmpty()){
        front = rear = 0;
    }else{
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    cout << value << " is being enqueued." << endl;
    display();
}

void dequeue(){
    if(isEmpty()){
        cout << "Queue is Empty. Nothing can be Dequeued." <<endl;
        return;
    }
    cout << queue[front] << " is being dequeued." << endl;
    if(front == rear){
        front = rear = -1;
    }else{
        front = (front + 1) % MAX;
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