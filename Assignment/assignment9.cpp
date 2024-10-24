#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// maxmimum element
#define MAX 50


// INFIX TO POSTFIX


char stack[MAX]; // character array
int TOS = -1; // top of stack character array

bool isFull(){
    return TOS == MAX - 1;
}

bool isEmpty(){
    return TOS == -1;
}

// check for operand
bool isOperand(char c){ 
    return isalnum(c); 
}

// push character
void pushchar(char c){
    if(isFull()){
        cout << "Cannot be pushed more elements." << endl;
        return;
    }

    stack[++TOS] = c;
}

// pop character
char popchar(){
    if(isEmpty()){
        cout << "Cannot delete more character." << endl;
        return '\0'; 
    }

    return stack[TOS--];
}

// peek character
char peek(){
    if(isEmpty()){
        return '\0';
    }

    return stack[TOS];
}

// check for precedence of oprerator
int precedence(char c){
    if(c == '^'){
        return 3;
    }

    if(c == '*' || c == '/'){
        return 2;
    }

    if(c == '+' || c == '-'){
        return 1;
    }
    return 0;
}

//check if inputed infix expression is valid or not (True or false)
bool validateinfix(string& infix){
    int open = 0;
    int close = 0;

    for(char c : infix){
        // is every character in string is alphabet or number or having invalid signs
        if(!isalnum(c) && !strchr("+-*/^()",c)){
            cout << "Invalid Input : " << c << endl;
            return false; 
        }
        if(c == '('){ 
            open++;
        }
        if(c == ')'){
            close++;
        }
    }

    if(open != close){
        cout << "Mismatched Paranthesis." << endl;
        return false;
    }

    return true;
}

// conversion 
string infixtopostfix(string & infix){
    string postfix = ""; // empty string

    if (infix.empty()) { // is expression empty
        cout << "Empty infix expression." << endl;
        return "";
    }

    for(char c : infix){
        if(c == '('){ 
            pushchar(c);
        }else if(isOperand(c)){
            postfix += c;
        }else if(c == ')'){
            while(!isEmpty() && peek() != '('){
                postfix += popchar();
            }
            if(!isEmpty() && peek() == '('){
                popchar();
            }
        }else{
            while(!isEmpty() && ((c != '^' && precedence(peek()) >= precedence(c)) || (c == '^' && precedence(peek()) > precedence(c)))){
                postfix += popchar();
            }
            pushchar(c);
        }
    }
    while (!isEmpty()){  
        postfix += popchar();
    }
    return postfix;
}

// EVALUATION 


int evalstack[MAX]; // integer stack
int evalTOS = -1; // Top of Stack integer

// integer push
void evalPush(int n){
    if (evalTOS == MAX - 1) {
        cout << "Overflow in evaluation stack." << endl;
        return;
    } 
    evalstack[++evalTOS] = n;
}

// integer pop
int evalPop(){
    if (evalTOS == -1) {
        cout << "Underflow in evaluation stack.";
        return 0;
    }
    return evalstack[evalTOS--];
}

//evaluate
int evaluatePostfix(string & postfix){
    int value[26] = {0}; //initialize to 0 array
    bool used[26] = {false};  // make it false array
    int count  = 0;

    for(char c : postfix){
        if(isalnum(c) && !used[c - 'a']){ // scan every character and make that used character true
            used[c - 'a'] = true;
            count++;
        }
    }

    for(int i = 0; i < 26; i++){ // get the value of every used character
        if(used[i]){
            cout << "Provide the value for " << char(i + 'a') << " : "; // ascii prevention
            cin >> value[i];
        }
    }

    // evaluation
    for (char c : postfix) {
        if (isalpha(c)) {
            evalPush(value[c - 'a']);
        } else if (isdigit(c)) {
            evalPush(c - '0');
        } else {
            int b = evalPop();
            int a = evalPop();

            switch (c) {
                case '+': 
                evalPush(a + b); 
                break;
                case '-': 
                evalPush(a - b); 
                break;
                case '*': 
                evalPush(a * b); 
                break;
                case '/':
                    if (b == 0) {
                        cout << "Division by zero error!" << endl;
                        return 0;
                    }
                    evalPush(a / b);
                    break;
                case '^': 
                evalPush(pow(a, b)); 
                break;
            }
        }
    }
    return evalPop();
}

int main() {
    string infix;
    int choice;

    do {
        cout << "Provide an infix expression (lowercase only): ";
        cin >> infix;

        if (!validateinfix(infix)){
            continue;
        }

        cout << "Infix Expression: " << infix << endl;
        string postfixExpression = infixtopostfix(infix);

        if (postfixExpression.empty()){
            continue;
        }

        cout << "Postfix Expression: " << postfixExpression << endl;
        cout << "Evaluate : " << evaluatePostfix(postfixExpression) << endl;

        cout << "Another infix expression? (1/0): ";
        cin >> choice;
    } while (choice != 0);

    return 0;
}

