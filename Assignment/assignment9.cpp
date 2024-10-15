#include <iostream>
using namespace std;

#define MAX 100

char stack[MAX];
int TOS = -1;

int intStack[MAX];
int intTOS = -1;

void push(char value){
    if(TOS == MAX-1){
        cout << "Stack overflown !" << endl;
        return;
    }

    stack[++TOS] = value;
}

char pop(){
    if(TOS == -1){
        cout << "Stack underflown !" << endl;
        return '\0';
    }

    return stack[TOS--];
}

void intPush(int value){
    if(intTOS == MAX - 1){
        cout << "Stack overflown !"<< endl;
        return;
    }

    intStack[++intTOS] = value;
}

int intPop(){
    if(intTOS == -1){
        cout << "Stack underflown !"<< endl;
        exit(0);
    }

    return intStack[intTOS--];
}

int precedence(char op) {
    if (op == '+' || op == '-'){
        return 1;
    } 
    if (op == '*' || op == '/'){
        return 2;
    }
    return 0;
}

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infixtoPostfix(char * infix, char * postfix){
    int j = 0;

    for(int i = 0; infix[i] != '\0'; i++){
        char c = infix[i];

        if(isalnum(c)){
        postfix[j++] = c;
        }

        else if(c == '('){
            push(c);
        }

        else if(c == ')'){
            while(TOS != -1 && stack[TOS] != '('){
                postfix[j++] = pop();
            }
            pop();
        }

        else if(isOperator(c)){
            while(TOS != -1 && precedence(stack[TOS]) >= precedence(c)){
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while(TOS != -1){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char * postfix){
    for(int i = 0; postfix[i] != '\0'; i++){
        char c = postfix[i];

         if(isdigit(c)){
        intPush(c - '0');    
        }else{
            int operator1 = intPop();
            int operator2 = intPop();

            switch(c){
                case '+':
                    intPush(operator1 + operator2);
                    break;
                case '-':
                    intPush(operator1 - operator2);
                    break;
                case '*':
                    intPush(operator1 * operator2);
                    break;
                case '/':
                    intPush(operator1 / operator2);
                    break;
            }
        }
    }
    return intPop();
}

int main(){
    char infix[MAX];
    char postfix[MAX];

    cout << "Enter the infix expression : ";
    cin >> infix;

    infixtoPostfix(infix,postfix);
    cout << "Postfix : " << postfix << endl;
    

    int result = evaluatePostfix(postfix);
    cout << "Evaluated Postfix : " << result << endl;
return 0;
}




