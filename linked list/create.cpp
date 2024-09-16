#include <iostream>
using namespace std;
struct node{
    
    int info;
    node * next;
};
int main(){
    node * n1 = (node *) malloc(sizeof(node));
    n1 -> info = 10;
    node * n2 = (node *) malloc (sizeof(node));
    n2 -> info = 20;
    n1 -> next = n2;
    node * n3 = (node *) malloc (sizeof(node));
    n3 -> info = 30;
    n2 -> next = n3;
    n3 -> next = NULL;
    node * head = n1;
    node* temp = head;
    while(temp != NULL){
        cout << temp-> info << " ";
        temp = temp -> next;
    }
    
    return 0;
}