#include <iostream>
using namespace std;
struct node{
    int data;
    node * next;
};
void insertAtEnd(node* & head, int data){
    node * newnode = (node*) malloc(sizeof(node));
    newnode -> data = data;
    newnode -> next = NULL;
    if(head == NULL){
        head = newnode;
        return;
    }
    node * temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;
}
void display(node * head){
    if(head == NULL){
        cout << "List is empty.";
        return;
    }

    node * temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
node * mergedlist(node * head1, node * head2){
    if (head1 == NULL) {
    return head2;
    }
    if (head2 == NULL) {
        return head1;
    }    
    node * newHead = NULL;
    if(head1 -> data <= head2 -> data){
        newHead = head1;
        newHead -> next = mergedlist(head1 -> next,head2);
    }else{
        newHead = head2;
        newHead -> next = mergedlist(head1 , head2 -> next);
    }
    return newHead;
}

int main(){
    node * list1 = NULL;
    node * list2 = NULL;
    int n,n1,data;
    cout << "Enter the size of List 1 : ";
    cin >> n;
    if(n <= 0){
        cout<<"\n\nSize of linked list cannot be 0 or less than 0\n\n";
        exit(0); 
    }
    for(int i = 0 ; i < n; i++){
        cout << "Enter " << i+1 <<" Elements of List 1 : ";
        cin >> data;
        insertAtEnd(list1,data);
    }
    cout << "Enter the size of List 2 : ";
    cin >> n1;
    if(n1 <= 0){
        cout<<"\n\nSize of linked list cannot be 0 or less than 0\n\n";
        exit(0); 
    }
    for(int i = 0 ; i < n1; i++){
        cout << "Enter "<<i+1 << " Elements of List 2 : ";
        cin >> data;
        insertAtEnd(list2,data);
    }
    cout << "List 1 : ";
    display(list1);
    cout << "\nList 2 : ";
    display(list2);
    node * result = mergedlist(list1,list2);
    cout << "\nSorted Array : ";
    display(result);
    return 0;
}