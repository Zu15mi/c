#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stk[MAX];
int top = -1;

void push(char x)
 {
    if (top == MAX - 1) 
	{
        printf("Stack Overflow\n");
        exit(1);
    }
    stk[++top] = x;
}

char pop() 
{
    if (top == -1) 
	{
        printf("Stack Underflow\n");
        exit(1);
    }
    return stk[top--];
}

void create()
 {
    top = -1;
}

int empty() 
{
    return (top == -1);
}

int priority(char op); 

void converttopostfix(char infix[])
{
	char token, topsymb;
	int i=0, error, donepop;
	
	printf("\n The postfic expression is : ");
	
	create(stk);
	error = 0;
	
	token=infix[i];
	
	while(token!='\0' && error!=1)
	{
		while(infix[i]==' ')
		i++;
		
		token=infix[i];
		
		if(token=='(')
		push(token);
		
		else if(token==')')
		{
			donepop=0;
			do {
				if(empty(stk)==1)
				error=1;
				else
				{
					topsymb=pop(stk);
					if(topsymb!='(')
					printf("%d", topsymb);
					else
					donepop=1;
				}
			}
			while(error!=1 && donepop!=1);
		}
		else if((token == '+') || (token == '-') || (token == '*') || (token == '/'))
		{
			donepop=0;
			while(empty(stk)!=1 && donepop!=1)
			{
				topsymb=pop(stk);
			if (priority(token) <= priority(topsymb))
				printf("%c", topsymb);
				else
				{ 
				push(topsymb);
				donepop = 1;
				}
			}
			push(token);
		}
		else if(token!='\0')
		printf("%c", token);
		i++;
	}
	
	while(empty(stk)!=1 && error!=1)
	//end of the expression
	{
	topsymb=pop(stk);
	if(topsymb!='(')
	printf("%c", topsymb);
	else
	error=1;	
	}
	
	if(error==1)
	printf("Error in infix expression.");
}

int priority(char op)
 {
    switch (op) 
	{
        case '(' : return 0;
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 2;
        default  : return -1;
    }
}

int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    converttopostfix(infix);

    return 0;
}
