#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for characters (operators)
char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;
    for(i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if(isdigit(ch)) {
            postfix[j++] = ch;
        } else if(ch == '(') {
            push(ch);
        } else if(ch == ')') {
            while(!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            pop(); // discard '('
        } else {
            while(!isEmpty() && precedence(ch) <= precedence(peek()))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while(!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';
}

// Stack for evaluation
int evalStack[MAX];
int evalTop = -1;

void pushEval(int val) {
    evalStack[++evalTop] = val;
}

int popEval() {
    return evalStack[evalTop--];
}

// Evaluate postfix expression (correct operand order)
int evaluatePostfix(char postfix[]) {
    int i, a, b;
    for(i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if(isdigit(ch)) {
            pushEval(ch - '0');
        } else {
            b = popEval();  // second operand
            a = popEval();  // first operand
            switch(ch) {
                case '+': pushEval(a + b); break;
                case '-': pushEval(a - b); break;
                case '*': pushEval(a * b); break;
                case '/': pushEval(a / b); break;
            }
        }
    }
    return popEval();
}

// Main function
int main() {
    char input[MAX], postfix[MAX];
    char mode;

    printf("Enter expression type - (i)nfix or (p)ostfix: ");
    scanf(" %c", &mode);  // space before %c skips newline

    printf("Enter the expression: ");
    scanf("%s", input);

    if (mode == 'i') {
        infixToPostfix(input, postfix);
        printf("Postfix: %s\n", postfix);
    } else if (mode == 'p') {
        strcpy(postfix, input);  // Already in postfix
    } else {
        printf("Invalid mode.\n");
        return 1;
    }

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}


