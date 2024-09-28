#include <iostream>
using namespace std;

struct node{
    int data;
    node * prev;
    node * next;
};

node * head = NULL;

void display(){

    if(head == NULL){
        cout << "Doubly Linked List is empty.";
        return;
    }

    node * temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

void insertAtStart(){
    int value;
    cout << "Enter the value you want to enter at start : ";
    cin >> value;

    node * newnode = (node*) malloc(sizeof(node));
    newnode -> data = value;
    newnode -> prev = NULL;
    newnode -> next = head;
    
    if(head != NULL){
        head -> prev = newnode;
    }

    head = newnode;
    display();
}

void insertAtEnd(){
    int value;
    cout << "Enter the value you want to enter at end : ";
    cin >> value;

    node * newnode = (node*) malloc(sizeof(node));
    newnode -> data = value;
    node * temp = head;

    if(head == NULL){
        cout << "As list is empty, number will be inserted at start." << endl;
        insertAtStart();
        return;
    }

    if(head != NULL){
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        newnode -> prev = temp;
        temp -> next = newnode;
        newnode -> next = NULL;
    }
    display();
}

void insertAfterValue(){
    int value,position;
    cout << "Enter the value you want to enter : ";
    cin >> value;

    cout << "Enter after which value you want to enter : ";
    cin >> position;

    node * newnode = (node*) malloc(sizeof(node));
    newnode -> data = value;

    node * temp = head;

    if(head == NULL){
        cout << "List is empty. Inserting at start." << endl;
        insertAtStart();
        return;
    }

    if(head != NULL){
        while(temp -> data != position){
            temp = temp -> next;
            if(temp == NULL){
                cout << position << " is not found." << endl;
                free(newnode);
                return;
            }
        }
        newnode -> next = temp -> next;
        newnode -> prev = temp;

        if(temp -> next != NULL){
            temp -> next -> prev = newnode;
        }

        temp -> next = newnode;
    }
    display();
}

void deleteAtStart(){
    if(head == NULL){
        cout << "Doubly Linked List is empty" << endl;
        return;
    }

    node * temp = head;

    head = head -> next;
    free(temp);
    display();
}

void deleteAtEnd(){
    if(head == NULL){
        cout << "Doubly Linked List is empty." << endl;
        return;
    }

    node * temp = head;

    if(temp -> next == NULL){
            free(head);
            head = NULL;
            cout<< "Doubly Linked List is empty." << endl;
            return;
        }

    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> prev -> next = NULL;
    free(temp);
    display ();
}

void deleteAtPosition(){
    if(head == NULL){
        cout << "Doubly Linked List is empty." << endl;
        return;
    }

    int value;
    cout << "Enter the value you want to delete : ";
    cin >> value;

    node * temp = head;

    if(temp -> data == value){
        deleteAtStart();
        return;
    }

    while(temp != NULL && temp -> data != value){
        temp = temp -> next;
    }
        if(temp == NULL){
            cout << value << " is not found."<<endl;
            return;
        }
        if(temp -> next == NULL){
            deleteAtEnd();
            return;
        }
    temp -> next -> prev = temp -> prev;
    temp -> prev -> next = temp -> next;

    free(temp);
    display();
}

int main(){
    int choice;
    while(true){
        cout << "\nMenu of Doubly Linked List : \n"<< endl;
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
         switch (choice)
        {
        case 1:
            insertAtStart();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAfterValue();
            break;
        case 4:
            deleteAtStart();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtPosition();
            break;
        case 7:
            display();
            break;
        case 8:
            cout << "Exiting....";
            exit(0);
            break;
        default:
            cout << "Invalid Input.";
            break;
        }
    }
    return 0;
}
