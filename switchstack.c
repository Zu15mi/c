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
	int ch;
	while(1)
	{printf("Enter 1 to push ,2 to pop,3 to peek , 4 to exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			{
				printf("ENTER ELEMENT TO PUSH \n");
		        scanf("%d",&x);
		        push(a,x);
		        break;
		
	            
			}
		case 2:
			{
				x=pop(a);
		        printf("%d\n",x);
		        break;
	        }
	    case 3:
	    	{
	    		y=peek(a);
	            printf(" Y= %d\n",y);
	            break;
			}
		case 4:
			{
				exit(1);
			}
	        
	}
}
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



