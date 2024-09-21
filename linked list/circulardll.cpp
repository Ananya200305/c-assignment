#include <iostream>
using namespace std;

struct node{
    int data;
    node * prev;
    node * next;
};
int main(){
    node * n1 = (node *) malloc(sizeof(node));
    node * n2 = (node *) malloc(sizeof(node));
    node * n3 = (node *) malloc(sizeof(node));
    n1 -> data = 10;
    n2 -> data = 20;
    n3 -> data = 30;
    node * head = n1;
    node * temp = head;


    n1 -> next = n2;
    n1 -> prev = n3;

    n2 -> next = n3;
    n2 -> prev = n1;

    n3 -> next = n1;
    n3 -> prev = n2;

    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    }while(temp != head);
    
    return 0;
}