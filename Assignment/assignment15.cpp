#include <iostream>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;
    int height;
};

int maix(int a, int b){
    return a>b?a:b;
}

int height(node * n){
    if(n == NULL){
        return 0;
    }else{
        return n -> height;
    }
}

node * createnode(int data){
    node * newNode = (node *) malloc(sizeof(node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> height = 1;

    return newNode;
}

int balanceFactor(node * n){
    if(n == NULL){
        return 0;
    }else{
        return height(n -> left) - height(n -> right);
    }
}

node * leftRotate(node * x){
    node * y = x -> right;
    node * T2 = y -> left;

    y -> left = x;
    x -> right = T2;

    y -> height = max(height(y -> right),height(y -> left)) +1;
    x -> height = max(height(x -> right),height(x -> left)) +1;

    return y;
}

node * rightRotate(node * y){
    node * x = y -> left;
    node * T2 = x -> right;

    x -> right = y;
    y -> left = T2;

    y -> height = max(height(y -> right), height(y -> left)) + 1;
    x -> height = max(height(x -> right), height(x -> left)) + 1;

    return x;
}

node * insert(node * root, int data){
    if(root == NULL){
        return createnode(data);
    }

    if(data < root -> data){
        root -> left = insert(root -> left, data);
    }else if(data > root -> data){
        root -> right = insert(root -> right, data);
    }
    return root;

    root -> height = max(height(root -> left), height(root -> right));
    int BF = balanceFactor(root);

    // left left
    if(BF > 1 && data < root -> left -> data){
        return rightRotate(root);
    }
    // right right
    if(BF < -1 && data > root -> right -> data){
        return leftRotate(root);
    }
    // left right
    if(BF > 1 && data > root -> left -> data){
        root -> left = leftRotate(root);
        return rightRotate(root);
    }
    // right left
    if(BF < -1 && data < root -> right -> data){
        root -> right = rightRotate(root);
        return leftRotate(root);
    }
    return root;
}

void inorder(node * root){
    if(root != NULL){
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

int main(){
    node * root = NULL;
    int choice, data;

    while(true){
        cout << "\nAVL Tree Menu :\n";
        cout << "1. Insert\n";
        cout << "2. In-order Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value you want to insert : ";
            cin >> data;
            root = insert(root,data);
            cout << data << " is inserted successfully." << endl;
            break;
        case 2:
            cout << "Inorder Traversal : ";
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Exiting..."<<endl;
            exit(0);
            break;
        default: 
            cout << "Invalid input." << endl;
            break;
        }
    }
    return 0;
}