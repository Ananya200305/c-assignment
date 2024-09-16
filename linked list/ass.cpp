#include <iostream>
#include <cstdlib> // Required for malloc and free
using namespace std;

// Single node
struct node { 
    int info;
    node* next;
};

node* head = NULL; // head is null

// Display the linked list
void display() {
    node* temp = head;
    if (temp == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert at the start
void insertAtStart() {
    int value;
    cout << "Enter the value you want to insert at start: ";
    cin >> value;

    // Use malloc to allocate memory
    node* newnode = (node*) malloc(sizeof(node));
    newnode->info = value;
    newnode->next = head;
    head = newnode;
}

// Insert at the end
void insertAtEnd() {
    if (head == NULL) {
        cout << "List is empty. Inserting at start." << endl;
        insertAtStart();
        return;
    }
    int value;
    cout << "Enter the value you want to insert at end: ";
    cin >> value;

    // Use malloc to allocate memory
    node* newnode = (node*) malloc(sizeof(node));
    newnode->info = value;
    newnode->next = NULL;

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Insert at a specific position (after a given value)
void insertAtPosition() {
    if (head == NULL) {
        cout << "List is empty. Inserting at start." << endl;
        insertAtStart();
        return;
    }

    int value, position;
    cout << "Enter the value you want to insert: ";
    cin >> value;
    cout << "Enter the value after which you want to insert: ";
    cin >> position;

    node* temp = head;
    while (temp != NULL && temp->info != position) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << position << " is not present in the list." << endl;
    } else {
        // Use malloc to allocate memory
        node* newnode = (node*) malloc(sizeof(node));
        newnode->info = value;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// Main function
int main() {
    int choice;

    while (true) {
        // Menu display
        cout << "\nMenu:\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Display the Linked List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu options
        switch (choice) {
            case 1:
                insertAtStart();
                display();
                break;
            case 2:
                insertAtEnd();
                display();
                break;
            case 3:
                insertAtPosition();
                display();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid input. Please try again." << endl;
        }
    }

    return 0;
}
