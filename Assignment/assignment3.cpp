#include <iostream>
using namespace std;

// Single node
struct node{ 
    int data;
    node * next;
};

node * head = NULL; // head is null

// Display
void display(){

    node*temp = head;

    if(temp == NULL){
        cout << "List is Empty.";
        return;
    }

    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }

    cout << endl;
}

// Insert at Start
void insertAtStart(){
    int value;
    cout << "Enter the value you want to insert at start : ";
    cin >> value;
    node*newnode = (node *) malloc(sizeof(node));
    newnode-> data = value;
    newnode -> next = head;
    head = newnode;
    display();
}

// Insert at End
void insertAtEnd(){
    if(head == NULL){
        cout << "List is Empty. Inserting at start." << endl;
        insertAtStart();
        return;
    }
    int value;
    cout << "Enter the value you want to insert at end : ";
    cin >> value;
    node*newnode = (node *) malloc(sizeof(node));
    newnode -> data = value;
    newnode -> next = NULL;
    node * temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;
    display();
}

// Insert at position
void insertAfterPosition(){
    if(head == NULL){
        cout << "List is empty. Inserting at start." << endl;
        insertAtStart();
        return;
    }
    int value,position;
    cout << "Enter the value you want to insert : ";
    cin >> value;
    cout << "Enter the value after which you want to insert : ";
    cin >> position;

    node * temp = head;

    while(temp != NULL && temp -> data != position){
        temp = temp -> next;
    }

    if(temp == NULL){
        cout << position << " is not present in the list." << endl;
    }else{
        node * newnode = (node *) malloc(sizeof(node));
        newnode -> data = value;
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
    display();
}

// Delete at Start
void deleteAtStart(){
    if(head == NULL){
        cout << "List is empty.";
        return;
    }
    node*temp = head;
    head = head -> next;
    free(temp);
    display();
}

// Delete at end
void deleteAtEnd(){
    if(head == NULL){
        cout << "List is empty.";
        return;
    }

    // one node
    if(head-> next == NULL){
        free(head);
        head = NULL;
        display();
        return;
    }


    node * temp = head;
    node * temp1 = NULL;
    while(temp -> next != NULL){
        temp1 = temp;
        temp = temp -> next;
    }
    temp1 -> next = NULL;
    free(temp);
    display();
}

// Delete at position
void deleteAtPosition(){
    if(head == NULL){
        cout << "List is Empty.";
        return;
    }
    int value;
    cout << "Enter the value you want to delete : ";
    cin >> value;

    node * temp = head;
    node * temp1 = NULL;

    // If there is only one node
    if(temp -> next == NULL){
        free(head);
        head = NULL;
        display();
        return;
    }

    // If node is at start
    if(temp != NULL && temp -> data == value){
        head = temp -> next;
        free(temp);
        display();
        return;
    }

    while(temp != NULL && temp -> data != value){
        temp1 = temp;
        temp = temp -> next;
    }
    if(temp == NULL){
        cout << value << " not found." << endl;;
    }else{
        temp1 -> next = temp -> next;
        free(temp);
    }
    display();
}

// Number of Nodes
int numberOfNodes(){
    int count = 0;
    node * temp = head;
    if(temp == NULL){
        cout << "List is empty. Number of nodes is 0.";
    }else{
    while(temp != NULL){
        count ++;
        temp = temp -> next;
    }
    cout << "Number of nodes are : " << count;
    }
    return count;
}

// reverse a linked list
void reverseList(){
    if(head == NULL){
        cout << "List is Empty." << endl;
        return;
    }
    if(head -> next == NULL){
        cout << "Single node only." << endl;
        display();
        return;
    }
    node * prev = NULL;
    node * curr = head;
    node * next = NULL;
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr ;
        curr = next;
    }
    head = prev;
    display();
}
int main(){
    int choice;
    while(true){
        cout << "\nMenu of Singly Linked list : \n"<< endl;
        cout << "Choose 1 to Insert at Start."<< endl;
        cout << "Choose 2 to Insert at End."<< endl;
        cout << "Choose 3 to Insert at Position." << endl;
        cout << "Choose 4 to Delete at Start." << endl;
        cout << "Choose 5 to Delete at End." << endl;
        cout << "Choose 6 to Delete a Position." << endl;
        cout << "Choose 7 to Display the number of Nodes." << endl;
        cout << "Choose 8 to Reverse the Linked List." << endl;
        cout << "Choose 9 to Display the Linked List." << endl;
        cout << "Choose 10 to EXIT." << endl;
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
            insertAfterPosition();
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
            numberOfNodes();
            break;
        case 8:
            reverseList();
            break;
        case 9:
            display();
            break;
        case 10:
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