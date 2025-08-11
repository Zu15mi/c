#include <stdio.h>
#include <stdlib.h>
#define MAX 80

void create()
{
	top=-1;
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


void converttoPostfix(char infix[])
{
	char stk[MAX],token,topsymb;
	int i=0,error,donepop;
	
	printf("\nPostfix expresion : ");
	create(stk);
	error=0;
	token=infix[i];
	while( token != '\0' && error != 1)
	{
		while(infix[i] == ' ')
		i++;
		token=infix[i];
		if(token == '(')
		push(stk,token);
		else if(token == ')')
		{
			donepop =0;
			do{
				if(empty(stk) == 1)
				error=1;
				else
				{
					topsymb=pop(stk);
					if(topsymb != '(')
					printf("%d",topsymb);
					else 
					donepop=1;
				}
			
			}while(error != 1 && donepop != 1);
		}
		else if(token == '+' ||token == '-' ||token == '*' ||token == '/')
		{
			donepop=0;
			while(empty(stk) != 1  && donepop != 1)
			{
				topymb =pop(stk);
				if(priority(token) <= priority(topsymb))
				printf("%c",topsymb);
				else
				{
					push(stk,topsymb);
					donepop=1;
				}
			}
			push(stk,token);
		}
		else if(token != '\0')
		printf("%c",token);
		i++;
	}
		
	while(empty(stk) != 1 && error != 1)
	{
		topsymb = pop(stk);
		if(topsymb != '(')
		printf("%c",topsymb);
		else
		error=1;
	}
	if(error == 1)
	printf("Error in infix");
}

int priority(char op)
{
	switch(op)
	{
		case '(': return 0;
		case '+': 
		case '-': return 1;
		case '*': 
		case '/': return 2;
	}
}

int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    converttoPostfix(infix);

    return 0;
}
