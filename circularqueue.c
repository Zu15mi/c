#define MAX 5
#include<stdio.h>
#include<stdlib.h>

int front=0,rear=-1,count=0;
int main()
{
	void insert(int[],int);
	int delete(int[]);
	int peek(int[]);
	void display(int []);
	int a[MAX],n,i,x,y,z;
	insert(a,10);
	insert(a,20);
	y=delete(a);
	printf("DELETED ELEMENT: %d\n",y);
	insert(a,30);
	y=delete(a);
	printf("DELETED ELEMENT: %d\n",y);
	insert(a,40);
	y=delete(a);
	printf("DELETED ELEMENT: %d\n",y);
	y=delete(a);
	printf("DELETED ELEMENT: %d\n",y);
	return 0;
}
void insert(int a[],int x)
{
	if(count>=MAX)
	{
		printf("Queue Full\n");
		exit(1);
	}
	else
	{
		count++;
		if(rear>=MAX-1)
		{
			rear=0;
		}
		else
		{
			rear++;
		}
		a[rear]=x;
	}
	
}
int delete(int a[])
{
	int x;
	if(count<=0)
	{
		printf("Queue Empty\n");
		exit(1);
		
	}
	else
	{
		count--;
		x=a[front];
		if(front>=MAX-1)
		{
			front=0;
		}
		else
		{
			front++;
		}
		return x;
	}
	
}
int peek(int a[])
{
	return (a[front]);
}
