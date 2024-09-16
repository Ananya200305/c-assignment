#include <iostream>
using namespace std;
struct node{
    int info;
    node * next;
};
int main(){
    node * n1 = (node * ) malloc(sizeof(node));
    node * n2 = (node *) malloc(sizeof(node));
    node * n3 = (node *) malloc(sizeof(node));
    n1 -> info = 10;
    n2 -> info = 20;
    n3 -> info = 30;
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n1; 
    node * head = n1;
    node * temp = head;
    do {
        cout << temp -> info << " ";
        temp = temp -> next;
    }
    while(temp != head);
    return 0;
}