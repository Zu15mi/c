#include <stdio.h>

#define MAX 80 //funtion prototype
int top =-1;
int a[MAX];

int eval(char);
int isdigit(char);
int oper(int,int,int);






int main()
{
	char exp[MAX];
	printf("\n Input the postfix expression:");
	scanf("%[^\n]", exp); //we are inputing a character one by one until we get a new line 
	printf("%d", eval (exp));
}

int eval (char exp[])
{
	int l, op1, op2, val i,j;
	char c;
	for(i=0; exp[i]!='\0'; i++)
	{
		c=exp[i];
		if(c==' ')
		continue;
		if(isdigit(c)==1)
		push(a, c-'0');
		else
		{
			op2=pop(a);
			op1=pop(a);
			val=oper(c,op1,op2);
			push (a, val);
		}
	}
	j=pop(a);
	return(j);
}

int isdigit(char sym)
{
	if((sym>='0') && (sym<='9'))
	return 1;
	else
	return 0;
}

int oper (int sym, int op1, int op2)
{
	switch(sym)
	{
		case '+': return(op1+op2);
		case '-': return(op1-op2);
		case '+': return(op1*op2);
		case '+': return(op1/op2);
	}
}

int pop(int a[]) {
	int x;
	if(top==-1)
    {
    	printf("\n Stack is empty");
    	exit (1);
    	else
    	
	}
}
