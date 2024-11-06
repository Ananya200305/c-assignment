#include <iostream>
using namespace std;

#define MAX 100

struct node{
    int data;
    node * left;
    node * right;
};

node * stack[MAX];
int TOS = -1;

bool isFull(){
    return TOS == MAX - 1;
}

bool isEmpty(){
    return TOS == -1;
}

void push(node * root){
    if(isFull()){
        cout << "Stack Overflown" << endl;
        return;
    }

    stack[++TOS] = root;
}

node * pop(){
    if(isEmpty()){
        cout << "Stack Underflown" << endl;
        return NULL;
    }

    return stack[TOS--];
}

node * createnode(int data){
    node * newNode = (node *) malloc(sizeof(node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

node * insert(node * root, int data){
    if(root == NULL){
        return createnode(data);
    }

    if(root -> data > data){
        root -> left = insert(root -> left, data);
    }else if(root -> data < data){
        root -> right = insert(root -> right, data);
    }
    return root;
}

node * inordersucc(node * root){ //smallest node of right subtree
    root = root -> right;
    while(root != NULL && root -> left != NULL){
        root = root -> left;
    }
    return root;
}

node * del(node * root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root -> data > key){
        root -> left = del(root -> left, key);
    }else if(root -> data < key){
        root -> right = del(root -> right , key);
    }else{
        if(root -> right == NULL && root -> left == NULL){
            free(root);
            return NULL;
        }else if(root -> right == NULL){
            node * temp = root -> left;
            free(root);
            return temp;
        }else if(root -> left == NULL){
            node * temp = root -> right;
            free(root);
            return temp;
        }

        node * temp = inordersucc(root);
        root -> data = temp -> data;
        root -> right = del(root -> right, temp -> data);
    }
    return root;
}

bool search(node * root, int key){
    if(root == NULL){
        return false;
    }

    if(root -> data == key){
        return true;
    }else if( root -> data < key){
        return search(root -> right, key);
    }else{
        return search(root -> left, key);
    }
}

void inorder(node * root){  // left root right
    node * temp = root;
    while(temp != NULL || !isEmpty()){
        while(temp != NULL){
            push(temp);
            temp = temp -> left;
        }
        temp = pop();
        cout << temp -> data << " ";
        temp = temp -> right;
    }
}

void preorder(node * root){ //root left right
    if(root == NULL){
        return;
    }
    push(root);
    while(!isEmpty()){
        node * temp = pop();
        cout << temp -> data << " ";

        if(temp -> right != NULL){
            push(temp -> right);
        }

        if(temp -> left != NULL){
            push(temp -> left);
        }
    }
}

void postorder(node * root){ //left right root
    if(root == NULL){
        return;
    }

    node * temp = root;
    node * lastvisited = NULL;

    while(temp != NULL || !isEmpty()){
        if(temp != NULL){
            push(temp);
            temp = temp -> left;
        }else{
            node * temp1 = stack[TOS];
            if(temp1 -> right == NULL || temp1 -> right == lastvisited){
                cout << temp1 -> data << " ";
                pop();
                lastvisited = temp1;
            }else{
                temp = temp1 -> right;
            }
        }
    }
}

int main(){
    int data;
    node * root = NULL;
    int choice, key;

    while(true){
        cout << "\nBinary Search Tree Operations\n";
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. INORDER TRAVERSAL" << endl;
        cout << "4. PREORDER TRAVERSAL" << endl;
        cout << "5. POSTORDER TRAVERSAL" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the value you want to insert : ";
                cin >> data;
                root = insert(root,data);
                cout << data << " is being inserted.";
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> key;
                if(search(root,key)){
                    root = del(root, key);
                    cout << key << " has been deleted." << endl;
                }else{
                    cout << key << " did not exist." << endl;
                }
                break;
            case 3:
                cout << "Inorder Traversal : ";
                inorder(root);
                break;
            case 4:
                cout << "Preorder Traversal : ";
                preorder(root);
                break;
            case 5:
                cout << "Postorder Traversal : ";
                postorder(root);
                break;
            case 6:
                cout << "Exiting...."<< endl;
                exit(0);
            default:
                cout << "Invalid Input." << endl;
                break;
        }
        
    }
    return 0;
}