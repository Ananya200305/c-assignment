#include <iostream>
using namespace std;

#define MAX 100

int adjMatrix[MAX][MAX] = {0};
int visited[MAX] = {0};

struct Queue{
    int queue[MAX];
    int front;
    int rear;

    Queue(){
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front  == -1;
    }

    bool isFull(){
        return rear == MAX -1;
    }

    void enqueue(int value){
        if(isFull()){
            cout << "Queue is Full" << endl;
            return;
        }

        if(isEmpty()){
            front = 0;
        }
        queue[++rear] = value;
    }

    int dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            exit(0);
        }

        int value = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front++;
        }
        return value;
    }
};

void BFS(int numNode , int start){
    Queue q;
    
    for(int i = 0 ; i < numNode; i++){
        visited[i] = 0;
    }

    q.enqueue(start);
    visited[start] = 1;

    cout << "BFS traversal starting from node " << start << ": ";
    while (!q.isEmpty()) {
        int currentNode = q.dequeue();
        cout << currentNode << " ";

        for (int i = 0; i < numNode; i++) {
            if (adjMatrix[currentNode][i] && !visited[i]) {
                q.enqueue(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

struct Stack {
    int stack[MAX];
    int top;

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is Full" << endl;
            return;
        }
        stack[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            exit(0);
        }
        return stack[top--];
    }
};

void DFS(int numNode, int start) {
    Stack s;

    // Reset the visited array
    for (int i = 0; i < numNode; i++) {
        visited[i] = 0;
    }

    s.push(start);
    visited[start] = 1;

    cout << "DFS traversal starting from node " << start << ": ";
    while (!s.isEmpty()) {
        int currentNode = s.pop();
        cout << currentNode << " ";

        // Visit adjacent nodes
        for (int i = numNode - 1; i >= 0; i--) { // Go in reverse order for correct DFS
            if (adjMatrix[currentNode][i] && !visited[i]) {
                s.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

int  main(){
    int choice, numNode, start;

    while(true){
        cout << "\nMenu : \n" << endl;
        cout << "1. INPUT GRAPH" << endl;
        cout << "2. PERFORM BFS" << endl;
        cout << "3. PERFORM DFS" << endl;
        cout << "4. EXIT" << endl;
        cout << "\n Enter Choice : ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Enter the number of nodes : ";
                cin >> numNode;

                cout << "Enter Adjacency Matrix : "<<endl;
                for(int i = 0; i < numNode; i++){
                    for(int j = 0; j < numNode; j++){
                        cout << "Enter the value of " << i << " " << j << " : ";
                        cin >> adjMatrix[i][j];
                        if(adjMatrix[i][j] != 0 && adjMatrix[i][j] != 1){
                            cout << "Invalid input! Only 0 or 1 allowed. Exiting...\n";
                            exit(0);
                        }
                    }
                }
            break;
            case 2:
                cout << "Enter the starting node : ";
                cin >> start;
                BFS(numNode, start);
            break;
            case 3:
                cout << "Enter the starting node : ";
                cin >> start;
                DFS(numNode, start);
            break;
            case 4:
                cout << "Exiting....." << endl;
                exit(0);
            break;
        default:
            cout << "Invalid Input." << endl;
        break;
        }
    }
    return 0;
}