#include <iostream>
using namespace std;

struct node {

    int data;
    node * prev;
    node * next;

};

node * head = NULL;

void display(){
    if(head == NULL){
        cout << "Doubly Circular Linked List is empty." << endl;
        return;
    }

    node * temp = head;

    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    }while(temp != head);
}

void insertAtStart(){
    int value;
    cout << "Enter the value you want to enter at start : ";
    cin >> value;

    node * newnode = (node*) malloc(sizeof(node));
    node * temp = head;
    newnode -> data = value;

    if(head == NULL){
        head = newnode;
        newnode -> next = newnode;
        newnode -> prev = newnode;
        display();
        return;
    }

    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> prev = temp;
    newnode -> next = head;
    head -> prev = newnode;
    head = newnode;

    display();
}

void insertAtEnd(){
    int value;
    cout << "Enter the value you want to enter at end : ";
    cin >> value;

    node * newnode = (node*) malloc(sizeof(node));
    node * temp = head;
    newnode -> data = value;

    if(head == NULL){
        cout << "As list is empty. We are inserting at start." << endl;
        insertAtStart();
        return;
    }

    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> prev = temp;
    newnode -> next = head;
    head -> prev = newnode;
    display();
}

void insertAfterValue(){
    if(head == NULL){
        cout << "Doubly Circular Linked List is empty." << endl;
        return;
    }

    int value , position;
    cout << "Enter the value you want to enter : ";
    cin >> value;

    cout<< "Enter the value after which you want to enter the value : ";
    cin >> position;

    node * newnode = (node *) malloc(sizeof(node));
    newnode -> data = value;
    node * temp = head;

    while(temp -> data != position){
        temp = temp -> next;
        if(temp == head){
            cout << position << " is not found." << endl;
            free(newnode);
            return;
        }
    }
    if(temp -> next == head){
        temp -> next = newnode;
        newnode -> prev = temp;
        newnode -> next = head;
        head -> prev = newnode;
        display();
        return;
    }
    newnode -> next = temp -> next ;
    temp -> next = newnode;
    newnode -> prev = temp;
    temp -> next -> prev = newnode;
    display();
}

void deleteAtStart(){
    if(head == NULL){
        cout << "Doubly Circular Linked List is empty.";
        return;
    }

    node * temp = head;

    if(temp -> next == head){
        free(temp);
        head = NULL;
        cout << "Doubly Circular Linked List is empty.";
        return;
    }

    node * last = head;

    while(last -> next != head){
        last = last -> next;
    }
    head = head -> next;
    last -> next = head;
    head -> prev = last;

    free(temp);
    
    display();
}

void deleteAtEnd(){
    if(head == NULL){
        cout << "Doubly Circular Linked List is empty.";
        return;
    }

    node * temp = head;

    if(temp -> next == head){
        free(temp);
        head = NULL;
        cout << "Doubly Circular Linked List is empty.";
        return;
    }

    while(temp -> next != head){
        temp = temp -> next;
    }

    temp -> prev -> next = head;
    head -> prev = temp -> prev;

    free(temp);
    display();
}

void deleteAtPosition(){
    if(head == NULL){
        cout << "Doubly Circular Linked List is empty." << endl;
        return;
    }

    int value;
    cout << "Enter the value you want to delete : ";
    cin >> value;

    node * temp = head;

    if(head -> data == value){
        deleteAtStart();
        return;
    }

    while(temp -> data != value){
        temp = temp -> next;
        if(temp == head){
            cout << value << " is not found." << endl;
            return;
        }
    }
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    free(temp);
    display();
}

int main(){
    int choice;
    while(true){
        cout << "\nMenu : \n"<< endl;
        cout << "Choose 1 to Insert at Start."<< endl;
        cout << "Choose 2 to Insert at End."<< endl;
        cout << "Choose 3 to Insert at Position." << endl;
        cout << "Choose 4 to Delete at Start." << endl;
        cout << "Choose 5 to Delete at End." << endl;
        cout << "Choose 6 to Delete a Position." << endl;
        cout << "Choose 7 to Display the Linked List." << endl;
        cout << "Choose 8 to EXIT." << endl;
        cout << "\n Choose a number : ";
        cin >> choice;
        if(choice == 1){
            insertAtStart();
        }else if(choice == 2){
            insertAtEnd();
        }else if(choice == 3){
            insertAfterValue();
        }else if(choice == 4){
            deleteAtStart();
        }else if(choice == 5){
            deleteAtEnd();
        }else if(choice == 6){
            deleteAtPosition();
        }else if(choice == 7){
            display();
        }else if(choice == 8){
            cout << "Exiting....";
            break;
        }else{
            cout << "Invalid Input.";
        }
    }
    return 0;
}