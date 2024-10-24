#include <iostream>
using namespace std;

// list using queue
struct nodeq{
    int data;
    nodeq * next;
};

nodeq * front = NULL;
nodeq * rear = NULL;

bool isQueueEmpty(){
    return front == NULL;
}

void displayQueue(){
    if(isQueueEmpty()){
        cout << "Queue is Empty." << endl;
        return;
    }

    nodeq * temp = front;
    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}

void enqueueQueue(){
    int value;
    cout << "Enter the value you want to enqueue : ";
    cin >> value;
    nodeq * newnode = (nodeq * ) malloc(sizeof(nodeq));
    newnode -> data = value;
    newnode -> next = NULL;
    if(isQueueEmpty()){
        front= rear = newnode;
    }else{
        rear -> next = newnode;
        rear = newnode;
    }
    cout << value << " is being enqueued to the queued." << endl;
    displayQueue();
}

void dequeueQueue(){
    if(isQueueEmpty()){
        cout << "Queue is empty. Cannot be dequeued." << endl;
        return;
    }

    cout << front -> data << " is being dequeued." << endl;
    nodeq * temp = front;
    front = front -> next;
    if(front == NULL){
        rear = NULL;
    }
    free(temp);
    displayQueue();
}


// list using stack
struct nodes{
    int data1;
    nodes * next;
};

nodes * tos = NULL;

bool isStackEmpty(){
    return tos == NULL;
}

void displayStack(){
    if(isStackEmpty()){
        cout << "Stack is Empty." << endl;
        return;
    }

    nodes * temp = tos;
    while(temp != NULL){
        cout << temp -> data1 << " " ;
        temp = temp -> next;
    }
    cout << endl;
}

void pushStack(){
    int value;
    cout << "Enter the value you want to push : ";
    cin >> value;
    nodes * newnode = (nodes * ) malloc(sizeof(nodes));
    newnode -> data1 = value;
    newnode -> next = tos;
    tos = newnode;
    cout << value << " is being pushed to the stack." << endl;
    displayStack();
}

void popStack(){
    if(isStackEmpty()){
        cout << "Stack is empty. Cannot be popped." << endl;
        return;
    }

    cout << tos -> data1 << " is being popped." << endl;
    nodes * temp = tos;
    tos = tos -> next;
    free(temp);
    displayStack();
}


int main(){
    int choice;
    while(true){
        cout << "\nChoose Data Structure :\n" << endl; 
        cout << "1. Stack using Linked List." << endl;
        cout << "2. Queue using Linked List." << endl;
        cout << "3. Exit" << endl;
        cout << "\nChoose : ";
        cin >> choice;
        switch (choice)
        {
        case 1:{
            int choice1;
            bool inStackMenu = true;
            while(inStackMenu){
            cout << "\nMenu :\n" << endl; 
            cout << "1. PUSH" << endl;
            cout << "2. POP" << endl;
            cout << "3. DISPLAY" << endl;
            cout << "4. GO TO MAIN MENU" << endl;
            cout << "Choose : ";
            cin >> choice1;
            switch (choice1)
            {
            case 1:
            pushStack();
            break;
            case 2:
            popStack();
            break;
            case 3:
            displayStack();
            break;
            case 4:
            inStackMenu = false;
            break;
            default:
            cout << "Invalid Input." << endl;
            break;
            }
        }
        break;
        }
        case 2: {
            int choice2;
            bool inQueueMenu = true;
            while(inQueueMenu){
            cout << "\nMenu :\n" << endl; 
            cout << "1. ENQUEUE" << endl;
            cout << "2. DEQUEUE" << endl;
            cout << "3. DISPLAY" << endl;
            cout << "4. GO TO MAIN MENU" << endl;
            cout << "Choose : ";
            cin >> choice2;
            switch (choice2)
            {
            case 1:
            enqueueQueue();
            break;
            case 2:
            dequeueQueue();
            break;
            case 3:
            displayQueue();
            break;
            case 4:
            inQueueMenu = false;
            break;
            default:
            cout << "Invalid Input." << endl;
            break;
            }
        }
        break;
        }
        case 3:
            cout << "Exiting..." << endl;
            exit(0);
        default:
            cout << "Invalid Input." << endl;
            break;
        }
    }
   
    return 0;
}