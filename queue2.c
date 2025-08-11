#define MAX 5
#include<stdio.h>
#include<stdlib.h>

int front=0,rear=-1;
int main()
{
	void insert(int[],int);
	int delete(int[]);
	int peek(int[]);
	int a[MAX],n,i,x,y;
	printf("HOW MANY ELEMENTS TO PUSH?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("ENTER ELEMENT TO PUSH \n");
		scanf("%d",&x);
		insert(a,x);
		
	}
	y=peek(a);
	printf("ELEMENT AT FRONT %d\n",y);
	
	for(i=0;i<n;i++)
	{
		x=delete(a);
		printf("DELETED ELEMENT %d\n",x);
		//("********************\n");
		//y=peek(a);
	    //printf("ELEMENT AT FRONT %d\n",y); 
		
	}
	return 0;
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

	
	
