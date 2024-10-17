#include <iostream>
using namespace std;


// Circular Queue Array
#define MAX 10

int arrayQueue[MAX];
int arrayFront = -1;
int arrayRear = -1;

bool isArrayEmpty(){
    return arrayFront == -1;
}

bool isArrayFull(){
    return (arrayRear + 1) % MAX == arrayFront;
}

void displayArray(){
    if(isArrayEmpty()){
        cout << "Queue is empty." << endl;
    }
    int i = arrayFront;
    do {
        cout << arrayQueue[i] << " ";
        i = (i+1) % MAX;
    }while(i != (arrayRear + 1) % MAX);
}

void enqueueArray(){
    int value;
    cout << "Enter the value you want to enqueue : ";
    cin >> value;
    if(isArrayFull()){
        cout << "Queue is Full. " << value << " cannot be enqueued." <<endl;
        return;
    }
    if(isArrayEmpty()){
        arrayFront = arrayRear = 0;
    }else{
        arrayRear = (arrayRear + 1) % MAX;
    }
    arrayQueue[arrayRear] = value;
    cout << value << " is being enqueued." << endl;
    displayArray();
}

void dequeueArray(){
    if(isArrayEmpty()){
        cout << "Queue is Empty. Nothing can be Dequeued." <<endl;
        return;
    }
    cout << arrayQueue[arrayFront] << " is being dequeued." << endl;
    if(arrayFront == arrayRear){
        arrayFront = arrayRear = -1;
    }else{
        arrayFront = (arrayFront + 1) % MAX;
    }
    displayArray();
}


// Circular Queue using linked list

struct node{
    int data;
    node * next;
};

node * listFront = NULL;
node * listRear = NULL;

bool isListEmpty(){
    return listFront == NULL;
}

void listdisplay(){
    if(isListEmpty()){
        cout << "Queue is empty." << endl;
        return;
    }

    node * temp = listFront;
    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    }while(temp != listFront);
}

void enqueueList(){
    int value;
    cout << "Enter the value you want to enqueue : ";
    cin >> value;
    
    node * newnode = (node *) malloc(sizeof(node));
    newnode -> data = value;

    if(isListEmpty()){
        listFront = newnode;
        listRear = newnode;
        newnode -> next = newnode;
    }else{
        listRear -> next = newnode;
        listRear = newnode ;
        listRear -> next = listFront;
    }
    cout << value << " is being enqueued in the queue." << endl;
    listdisplay();
}

void dequeueList(){
    if(isListEmpty()){
        cout << "Queue is empty. Cannot be dequeued." << endl;
        return;
    }
    if(listFront == listRear){
        cout << listFront -> data << " is being dequeued from the queue." << endl;
        free(listFront);
        listFront = listRear = NULL;
    }else{
        node * temp = listFront;
        cout << listFront -> data << " is being dequeued from in the queue." << endl;
        listFront = listFront -> next;
        listRear -> next = listFront;
        free(temp);
    }
    listdisplay();
}

int main(){
    int choice;
    while(true){
        cout << "\nChoose Queue type :\n" << endl; 
        cout << "1. Circular Queue using Array." << endl;
        cout << "2. Circular Queue using Linked List." << endl;
        cout << "3. Exit" << endl;
        cout << "\nChoose : ";
        cin >> choice;
        switch (choice)
        {
        case 1:{
            int choice1;
            bool inArrayMenu = true;
            while(inArrayMenu){
            cout << "\nMenu :\n" << endl; 
            cout << "1. ENQUEUE" << endl;
            cout << "2. DEQUEUE" << endl;
            cout << "3. DISPLAY" << endl;
            cout << "4. GO TO MAIN MENU" << endl;
            cout << "Choose : ";
            cin >> choice1;
            switch (choice1)
            {
            case 1:
            enqueueArray();
            break;
            case 2:
            dequeueArray();
            break;
            case 3:
            displayArray();
            break;
            case 4:
            inArrayMenu = false;
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
            bool inListMenu = true;
            while(inListMenu){
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
            enqueueList();
            break;
            case 2:
            dequeueList();
            break;
            case 3:
            listdisplay();
            break;
            case 4:
            inListMenu = false;
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