#include <iostream>
using namespace std;

// Single node
struct node{ 
    int info;
    node * next;
};

node * head = NULL; // head is null

// Display
void display(){
    node*temp = head;
    if(temp == NULL){
        cout << "List is Empty.";
    }
    while(temp != NULL){
        cout << temp -> info << " " ;
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
    newnode-> info = value;
    newnode -> next = head;
    head = newnode;
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
    newnode -> info = value;
    node * temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> next = NULL;
}

// Insert at position
void insertAtPosition(){
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
    while(temp != NULL && temp -> info != position){
        temp = temp -> next;
    }

    if(temp == NULL){
        cout << position << " is not present in the list." << endl;
    }else{
        node * newnode = (node *) malloc(sizeof(node));
        newnode -> info = value;
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
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
    if(head-> next == NULL){
        free(head);
        head = NULL;
        display();
        return;
    }
    node * temp = head;
    node * prev = NULL;
    while(temp -> next != NULL){
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
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
    node * prev = NULL;

    // If there is only one node
    if(temp -> next == NULL){
        free(head);
        head = NULL;
        display();
        return;
    }

    // If node is at start
    if(temp != NULL && temp -> info == value){
        head = temp -> next;
        free(temp);
        display();
        return;
    }

    while(temp != NULL && temp -> info != value){
        prev = temp;
        temp = temp -> next;
    }
    if(temp == NULL){
        cout << value << " not found." << endl;;
    }else{
        prev -> next = temp -> next;
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
    node * temp = head;
    node * next = NULL;
    while(temp != NULL){
        next = temp -> next;
        temp -> next = prev;
        prev = temp ;
        temp = next;
    }
    head = prev;
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
        cout << "Choose 7 to Display the number of Nodes." << endl;
        cout << "Choose 8 to Reverse the Linked List." << endl;
        cout << "Choose 9 to Display the Linked List." << endl;
        cout << "Choose 10 to EXIT." << endl;
        cout << "\n Choose a number : ";
        cin >> choice;
        if(choice == 1){
            insertAtStart();
            display();
        }else if(choice == 2){
            insertAtEnd();
            display();
        }else if(choice == 3){
            insertAtPosition();
            display();
        }else if(choice == 4){
            deleteAtStart();
        }else if(choice == 5){
            deleteAtEnd();
        }else if(choice == 6){
            deleteAtPosition();
        }else if(choice == 7){
            numberOfNodes();
        }else if(choice == 8){
            reverseList();
        }else if(choice == 9){
            display();
        }else if(choice == 10){
            cout << "Exiting....";
            break;
        }else{
            cout << "Invalid Input.";
        }
    }
    return 0;
}