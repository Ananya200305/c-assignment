#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * left;
    Node * right;
};

Node * createNode(int data){
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node * insert(Node * root, int data){
    if(root == NULL){
        return createNode(data);
    }

    if(data > root -> data){
        root -> right = insert(root -> right, data);
    }else if(data < root -> data){
        root -> left = insert(root -> left,data);
    }
    return root;
}

bool search(Node * root, int key){
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

Node * inodersucc(Node * root){ // smallest node of right subtree
    root = root -> right;
    while(root != NULL && root -> left != NULL){
        root = root -> left;
    }
    return root;
}

Node * inorderpred(Node * root){ //largest node of left subtree
    root = root -> left;
    while(root != NULL && root -> right != NULL){
        root = root -> right;
    }
    return root;
}

Node * delsuc(Node * root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root -> data > key){
        root -> left = delsuc(root -> left,key);
    }else if(root -> data < key){
        root -> right = delsuc(root -> right, key);
    }else{
        if(root -> left == NULL){
            Node * temp = root -> right;
            free(root);
            return temp;
        }else if(root -> right == NULL){
            Node * temp = root -> left;
            free(root);
            return temp;
        }

        Node * temp = inodersucc(root);
        root -> data = temp -> data;
        root -> right = delsuc(root -> right, temp -> data);
    }
    return root;
}

Node * delpred(Node * root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root -> data > key){
        root -> left = delpred(root -> left,key);
    }else if(root -> data < key){
        root -> right = delpred(root -> right,key);
    }else{
        if(root -> left == NULL){
            Node * temp = root -> right;
            free(root);
            return temp;
        }else if(root -> right == NULL){
            Node * temp = root -> left;
            free(root);
            return temp;
        }

        Node * temp = inorderpred(root);
        root -> data = temp -> data;
        root -> left = delpred(root -> left, temp -> data);
    }
    return root;
}

//left root right
void inorder(Node * root){
    if(root != NULL){
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

//root left right
void preorder(Node * root){
    if(root != NULL){
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

//left right root
void postorder(Node * root){
    if(root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}

int main(){
    int data;
    Node * root = NULL;
    int choice;
    int key;
    int type;

    while(true){
        cout << "\n MENU : \n" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. SEARCH" << endl;
        cout << "3. DELETE" << endl;
        cout << "4. INORDER TRAVERSAL" << endl;
        cout << "5. PREORDER TRAVERSAL" << endl;
        cout << "6. POSTORDER TRAVERSAL" << endl;
        cout << "7. EXIT" << endl;
        cout << "\n Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value you want to insert : ";
            cin >> data;
            root = insert(root,data);
            cout << data << " is being inserted." << endl;
            break;
        case 2:
            cout << "Enter the value you want to search : ";
            cin >> key;
            if(search(root,key)){
                cout << key << " is found." << endl;
            }else{
                cout << key << " is not found." << endl;
            }
            break;
        case 3:
                cout << "1. Inorder Sucessor" << endl;
                cout << "2. Inorder Predecessor" << endl;
                cout << "Enter the type of Deletion : ";
                cin >> type;
                if(type == 1){
                    cout << "Enter the value to delete: ";
                    cin >> key;
                    root = delsuc(root, key);
                    if(root == NULL){
                        cout << "Tree is empty. Cannot delete " << key << "." << endl;
                        break;
                    }
                    cout << key << " has been deleted.";
                    break;
                }else if(type == 2){
                    cout << "Enter the value to delete: ";
                    cin >> key;
                    root = delpred(root, key);
                    if(root == NULL){
                        cout << "Tree is empty. Cannot delete " << key << "." << endl;
                        break;
                    }
                    cout << key << " has been deleted.";
                    break;
                }else{
                    cout << "Invalid."<< endl;
                    break;
                }
                break;
        case 4:
            cout << "Inorder : ";
            inorder(root);
            break;
        case 5:
            cout << "Preorder : ";
            preorder(root);
            break;
        case 6:
            cout << "Postorder : ";
            postorder(root);
            break;
        case 7:
            cout << "Exiting...."<< endl;
            exit(0);
        default:
            cout << "Invalid Input "<< endl;
            break;
        }
    }
    return 0;
}