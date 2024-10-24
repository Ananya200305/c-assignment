#include <iostream>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;
};

node * createNode(int data){
    node * newNode = (node *) malloc(sizeof(node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

struct node * insert(node * root, int data){
    if(root == NULL){
        return createNode(data);
    }

    if(data < root -> data){
        root -> left = insert(root -> left , data);
    }else if(data > root -> data){
        root -> right = insert(root -> right, data);
    }
    return root;
}

bool search(node * root, int key){
    if(root == NULL){
        return false;
    }

    if(root -> data == key){
        return true;
    }else if(root -> data < key){
        return search(root -> right, key);
    }else{
        return search(root -> left, key);
    }
}

node * inordersucc(node * root){
    root = root -> right;
    while(root != NULL && root -> left != NULL){
        root = root -> left;
    }
    return root;
}

node * del(node * root,int key){
    if(root == NULL){
        return root;
    }

    if(root -> data < key){
        root -> right = del(root -> right,key);
    }else if(root -> data > key){
        root -> left = del(root -> left, key);
    }else{
        if(root -> left == NULL){
            node * temp = root -> right;
            free(root);
            return temp;
        }else if(root -> right == NULL){
            node * temp = root -> left;
            free(root);
            return temp;
        }

        node * temp = inordersucc(root);
        root -> data = temp -> data;
        root -> right = del(root -> right, temp -> data);
    }
    return root ;
}

// Left Root Right
void inorder(node * root){
    if(root != NULL){
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

// Root Left Right
void preorder(node * root){
    if(root != NULL){
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

// Left Right Root
void postorder(node * root){
    if(root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}

int main(){
    int data;
    node * root = NULL;
    int choice, key;

    while(true){
        cout << "\nBinary Search Tree Operations\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
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
                cout << "Enter the value to search: ";
                cin >> key;
                if (search(root, key)) {
                    cout << key << " found in the tree." << endl;
                } else {
                    cout << key << " not found in the tree." << endl;
                }
                break;
            case 4:
                cout << "Inorder Traversal : ";
                inorder(root);
                break;
            case 5:
                cout << "Preorder Traversal : ";
                preorder(root);
                break;
            case 6:
                cout << "Postorder Traversal : ";
                postorder(root);
                break;
            case 7:
                cout << "Exiting...."<< endl;
                exit(0);
            default:
                cout << "Invalid Input." << endl;
                break;
        }
        
    }
    return 0;
}