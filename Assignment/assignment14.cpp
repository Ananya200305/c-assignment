#include <iostream>
using namespace std;

#define MAX 100

struct treenode{
    int data;
    treenode * left;
    treenode * right;
};

treenode * createnode(int data){
    treenode * newNode = (treenode *) malloc(sizeof(treenode));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

treenode * insert(treenode * root, int data){
    if(root == NULL){
        return createnode(data);
    }

    if(data < root -> data){
        root -> left = insert(root -> left, data);
    }else if(data > root -> data){
        root -> right = insert(root -> right,data);
    }
    return root;
}

treenode * inordersucc(treenode * root){
    root = root -> right;
    while(root != NULL && root -> left != NULL){
        root = root -> left;
    }
    return root;
}

treenode * del(treenode * root,int key){
    if(root == NULL){
        return root;
    }

    if(root -> data < key){
        root -> right = del(root -> right,key);
    }else if(root -> data > key){
        root -> left = del(root -> left, key);
    }else{
        if(root -> left == NULL){
            treenode * temp = root -> right;
            free(root);
            return temp;
        }else if(root -> right == NULL){
            treenode * temp = root -> left;
            free(root);
            return temp;
        }

        treenode * temp = inordersucc(root);
        root -> data = temp -> data;
        root -> right = del(root -> right, temp -> data);
    }
    return root ;
}

treenode * stack[MAX];
int TOS = -1;

bool isEmpty(){
    return TOS == -1;
}

bool isFull(){
    return TOS == MAX -1;
}

void push(treenode * root){
    if(isFull()){
        cout << "Stack Overflown" << endl;
        return;
    }

    stack[++TOS] = root;
}

treenode * pop(){
    if(isEmpty()){
        cout << "Stack Underflown "<< endl;
        return NULL;
    }

    return stack[TOS--];
}

//left root right
void inorder(treenode * root){
    treenode * temp = root;
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

// root left right
void preorder(treenode * root){
    if(root == NULL){
        return;
    }
    push(root);
    while(!isEmpty()){
        treenode * temp = pop();
        cout << temp -> data << " ";

        if(temp -> right != NULL){
            push(temp -> right);
        }
        if(temp -> left != NULL){
            push(temp -> left);
        }
    }
}

// left right root
void postorder(treenode * root) {
    if (root == NULL) {
        return;
    }

    treenode* temp = root;
    treenode* lastVisited = NULL;

    while (temp != NULL || !isEmpty()) {
        if (temp != NULL) {
            push(temp); 
            temp = temp->left;
        } else {
            treenode* temp1 = stack[TOS]; 
            if (temp1->right == NULL || temp1->right == lastVisited) {
                cout << temp1->data << " "; 
                pop(); 
                lastVisited = temp1; 
            } else {
                temp = temp1->right; 
            }
        }
    }
}



int main(){
    int data;
    treenode * root = NULL;
    int choice, key;

    while(true){
        cout << "\nBinary Search Tree Operations\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Exit\n";
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
                root = del(root, key);
                cout << key << " has been deleted (if it existed).\n";
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