#define MAX 5
#include<stdio.h>
#include<stdlib.h>

int front=0,rear=-1;
int main()
{
	void insert(int[],int);
	int delete(int[]);
	void display(int[]);
	int a[MAX],n,i,x,y;
    int ch;
	while(1)
	{
	printf("Enter 1 to insert , 2 to delete, 3 to peek , 4 to exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			{
				printf("ENTER ELEMENT TO PUSH \n");
		        scanf("%d",&x);
		        insert(a,x);
		        break;
		
	            
			}
		case 2:
			{
				x=delete(a);
		        printf("DELETED ELEMENT: %d\n",x);
		        break;
	        }
	    case 3:
	    	{
	    		y=peek(a);
	            printf("ELEMENT AT FRONT = %d\n",y);
	            break;
			}
		case 4:
			{
				exit(1);
			}
	        
	}
}
}
void insert(int a[],int x)
{
	++rear;
	if(rear==MAX)
	{
		printf("Queue Full\n");
		exit(1);
	}
	a[rear]=x;
}
int delete(int a[])
{
	int x;
	if(front>rear)
	{
		printf("Queue Empty\n");
		exit(1);
		
	}
	x=a[front];
	front++;
	return x;
}
int peek(int a[])
{
	return (a[front]);
}
