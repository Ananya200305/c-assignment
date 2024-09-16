#include <iostream>
using namespace std;

// Structure of a Node
struct node{
    int info;
    node * next;
};

// head is null
node * head = NULL;

// display
void display(){
    if(head == NULL){
        cout << "Circular Linked List is empty." << endl;
        return;
    }

    node * temp = head;

    // print
    do{
        cout << temp -> info << " ";
        temp = temp -> next;
    }while(temp != head);

    cout << endl;
}

// insert at start
void insertAtStart(){
    int value;
    cout << "Enter the value you want to insert at start : ";
    cin >> value;

    // new node
    node * newnode = (node *) malloc(sizeof(node));
    newnode -> info = value;
    
    if(head == NULL){
        head = newnode;
        newnode -> next = head;
    }else{
        node * temp = head;
        while (temp -> next != head){
            temp = temp -> next;
        }
        newnode -> next = head;
        temp -> next = newnode;
        head = newnode;
    }
    display();
}

// insert at end
void insertAtEnd(){
    int value;
    cout << "Enter the value you want to insert at end : ";
    cin >> value;

    // new node
    node * newnode = (node *) malloc(sizeof(node));
    newnode -> info = value;

    if(head == NULL){
        head = newnode;
        newnode -> next = head;
        return;
    }else{
        node * temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> next = head;
    }
    display();
}

// instertion at a position
void insertAtPosition(){
    int value, position;
    cout << "Enter the value you want to insert : ";
    cin >> value;
    cout << "Enter after which value you want to insert : ";
    cin >> position;

    node * newnode = (node * ) malloc(sizeof(node));
    newnode -> info = value;

    if(head == NULL){
        cout << "List is empty." << endl;
        free(newnode);
        return;
    }

    node * temp = head;

    while(temp -> info != position){
        temp = temp -> next;
        if(temp == head){
            cout << position << " is not present." << endl;
            free(newnode);
            return;
        }
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
    display();
}

// delete at start
void deleteAtStart(){
    if(head == NULL){
        cout << "List is empty";
        return;
    }

    node * temp = head;

    if(head -> next == head){
        head = NULL;
    }else{
        node * current = head;
        while(current -> next != head){
            current = current -> next;
        }
        current -> next = head -> next;
        head = head -> next;
    }
    free(temp);
    display();
}

void deleteAtEnd(){
    if(head == NULL){
        cout << "List is empty";
        return;
    }

    node * temp = head;

    if(head -> next == head){
        head = NULL;
    }else{
        node * prev = NULL;
        while(temp -> next != head){
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = head;
    }
    free(temp);
    display();
}

void deleteAtPosition(){
    if(head == NULL){
        cout << "List is empty";
        return;
    }

    int value;
    cout << "Enter the value you want to delete : ";
    cin >> value;
    node * temp = head;
    node * prev = NULL;

    while(temp -> info != value){
        prev = temp;
        temp = temp->next;
        if(temp == head){
            cout << value << " is not found.";
            return;
        }
        prev -> next = temp -> next;
        free(temp);
        display();
    }
}
int main () {
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
            insertAtPosition();
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