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
    return rear == MAX - 1;
}

void display(){
    if(isEmpty()){
        cout << "Queue is Empty." << endl;
        return;
    }

    for(int i = front; i <= rear; i++){
        cout << queue[i] << " ";
    }
}

void enqueue(){
    int value;
    cout << "Enter the value to enqueue : ";
    cin >> value;
    if(isFull()){
        cout << "Queue is full. " << value << " cannot be added."<<endl;
        display();
        return;
    }
    if(isEmpty()){
        front = 0;
    }
    rear++;
    queue[rear] = value;
    cout << value << " is been enqueueed." << endl;
    display();
}

void dequeue(){
    if(isEmpty()){
        cout << "Queue is empty. Cannot be dequeued." << endl;
        return;
    }
    cout << queue[front] << " is dequeued from the queue." << endl;

    if(front == rear){
        front = rear = -1;
    }else{
        front++;
    }
    display();
}

int peek(){
    if(isEmpty()){
        cout << "Queue is empty. Nothing to peek." << endl;
        return -1;
    }
    cout << "Top of Queue : " << queue[front] << endl;
    return queue[front];
}

int main(){
    int choice;
    while(true){
        cout << "\nMenu :\n" << endl; 
        cout << "1. ENQUEUE" << endl;
        cout << "2. DEQUEUE" << endl;
        cout << "3. PEEK" << endl;
        cout << "4. DISPLAY" << endl;
        cout << "5. EXIT" << endl;
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
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Exiting....." << endl;
            exit(0);
        default:
            cout << "Invalid Input." << endl;
            break;
        }
    }
    return 0;
}