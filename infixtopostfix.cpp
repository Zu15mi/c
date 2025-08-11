#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  

#define MAX 80

char stk[MAX];
int top = -1;


void create(char stack[]) {
    top = -1;
}

int empty(char stack[]) {
    return top == -1;
}

void push(char stack[], char symbol) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    } else {
        stack[++top] = symbol;
    }
}

char pop(char stack[]) {
    if (empty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        return stack[top--];
    }
}

char peek(char stack[]) {
    if (empty(stack)) {
        return '\0';
    }
    return stack[top];
}

int priority(char op) {
    switch(op) {
        case '(': return 0;
        case '+': 
        case '-': return 1;
        case '*': 
        case '/': return 2;
        default: return -1;
    }
}

void converttoPostfix(char infix[]) {
    char token, topsymb;
    int i = 0, error = 0, donepop;

    printf("\nPostfix expression: ");
    create(stk);

    token = infix[i];
    while(token != '\0' && error != 1) {
        while(infix[i] == ' ') i++; 

        token = infix[i];
        if (token == '\0') break;

        if (token == '(') {
            push(stk, token);
        } else if (token == ')') {
            donepop = 0;
            do {
                if (empty(stk)) {
                    error = 1;
                } else {
                    topsymb = pop(stk);
                    if (topsymb != '(') {
                        printf("%c", topsymb);
                    } else {
                        donepop = 1;
                    }
                }
            } while (!donepop && !error);
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            donepop = 0;
            while (!empty(stk) && !donepop) {
                topsymb = pop(stk);
                if (priority(token) <= priority(topsymb)) {
                    printf("%c", topsymb);
                } else {
                    push(stk, topsymb);
                    donepop = 1;
                }
            }
            push(stk, token);
        } else if (isalnum(token)) {  
            printf("%c", token);
        } else {
            
            error = 1;
        }
        i++;
    }

    while (!empty(stk) && !error) {
        topsymb = pop(stk);
        if (topsymb != '(')
            printf("%c", topsymb);
        else
            error = 1;
    }

    if (error == 1)
        printf("\nError in infix expression.");
    printf("\n");
}


int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    converttoPostfix(infix);

    return 0;
}

