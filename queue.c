#define size 5
#include<stdio.h>
#include<stdlib.h>

int top=-1;
int main()
{
	void push(int[],int);
	int pop(int[]);
	int peek(int[]);
	int a[size],n,i,x,y;
	printf("HOW MANY ELEMENTS TO PUSH?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("ENTER ELEMENT TO PUSH \n");
		scanf("%d",&x);
		push(a,x);
		
	}
	y=peek(a);
	printf("%d",y);
	for(i=0;i<n;i++)
	{
		x=pop(a);
		printf("%d",x);
	}
	return 0;
}
void push(int a[],int x)
{
	int max=size;
	++top;
	if(top==max)
	{
		printf("STACK FULL\n");
		exit(1);
	  	
	}
	a[top]=x;
}
int pop(int a[])
{
	int x;
	if(top==-1)
	{
		printf("STACK EMPTY\n");
		exit(1);
		
	}
	x=a[top];
	top--;
	return x;
	
}
int peek(int a[])
{
	return (a[top]);
}




