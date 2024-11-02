#include <iostream>
using namespace std;

#define MAX 100

int adjMatrix[MAX][MAX] = {0};
int visited[MAX] = {0};
int nodeValue[MAX];

struct Queue{
    int queue[MAX];
    int front;
    int rear;

    Queue(){
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return rear == MAX - 1;
    }

    void enqueue(int value){
        if(isFull()){
            cout << "Queue is full" << endl;
            return;
        }

        if(isEmpty()){
            front = 0;
        }
        queue[++rear] = value;
    }

    int dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty." << endl;
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

void BFS(int numNode, int start){
    Queue q;

    for(int i = 0; i < numNode; i++){
        visited[i] = 0;
    }

    int startIndex = -1;
    for(int i = 0; i < numNode; i++){
        if(nodeValue[i] == start){
            startIndex = i;
            break;
        }
    }

    if(startIndex == -1){
        cout << "Invalid starting node!" << endl;
        return;
    }

    q.enqueue(startIndex);
    visited[startIndex] = 1;

    while(!q.isEmpty()){
        int current = q.dequeue();
        cout << nodeValue[current] << " ";

        for(int i = 0; i < numNode; i++){
            if(adjMatrix[current][i] == 1 && !visited[i]){
                q.enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

struct Stack{
    int stack[MAX];
    int TOS;

    Stack(){
        TOS = -1;
    }

    bool isFull(){
        return TOS == MAX -1;
    }

    bool isEmpty(){
        return TOS == -1;
    }

    void push(int value){
        if(isFull()){
            cout << "Stack OverFlown" << endl;
            return;
        }

        stack[++TOS] = value;
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack UnderFlown" << endl;
            exit(0);
        }

        return stack[TOS--];
    }
};

void DFS(int numNode, int start){
    Stack s;

    for(int i = 0; i < numNode; i++){
        visited[i] = 0;
    }

    int startIndex = -1;
    for(int i = 0 ; i < numNode; i++){
        if(nodeValue[i] == start){
            startIndex = i;
            break;
        }
    }

    if(startIndex == -1){
        cout << "Invalid starting node." << endl;
        return;
    }

    s.push(startIndex);
    visited[startIndex] = 1;

    while (!s.isEmpty()){
        int current = s.pop();
        cout << nodeValue[current] << " ";

        for(int i = numNode - 1; i >= 0; i--){
            if(adjMatrix[current][i] == 1 && !visited[i]){
                s.push(i);
                visited[i] = 1;
            }
        }
    }
    
}


int main(){
    int choice, numNode, start;
    while(true){
        cout << "\n Menu : \n" << endl;
        cout << "1. INSERT GRAPH" << endl;
        cout << "2. PERFORM BFS" << endl;
        cout << "3. PERFORM DFS" << endl;
        cout << "4. EXIT" << endl;
        cout << "\n Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number of nodes (from 0 to " << MAX - 1 << ") : ";
            cin >> numNode;

            if (numNode > MAX || numNode <= 0) {
                cout << "Invalid number of nodes!" << endl;
                break;
            }

            cout << "Enter the Node values : " << endl;
            for(int i = 0; i < numNode; i++){
                cout << "Enter the value of node " << i+1 << " : ";
                cin >> nodeValue[i];
            }

            cout << "Enter Adjacency Matrix (only 0 or 1) : " << endl;
            for(int i = 0 ; i < numNode; i++){
                for(int j = 0; j < numNode; j++){
                    cout << "Enter value for " << nodeValue[i] << " " << nodeValue[j] << " : ";
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
            BFS(numNode,start);
            break;
        case 3:
            cout << "Enter the starting node : ";
            cin >> start;
            DFS(numNode,start);
            break;
        case 4:
            cout << "Exiting....";
            exit(0);
            break;
        default:
            cout << "Invalid input." << endl;
            break;
        }
    }
    return 0;
}