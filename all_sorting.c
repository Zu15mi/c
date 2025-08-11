#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
void selection(int a[])
{
	int i,j,temp;
	for(i=0;i<SIZE-1;i++)
	{
		for(j=j+1;i<SIZE;j++)
		if(a[i]>a[j])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	
	}
	printf("after sorting the array");
	
		for(i=0;i<SIZE;i++)
		{
		
		printf("%d ",a[i]);
	}
}
void bubble_sort(int a[])
{
	int i,j;
	int flag=1;
	for(i=0;i<SIZE-1;i++)
	{
		for(j=0;j<SIZE-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		}
	}
	printf("after sorting the array");
	
		for(i=0;i<SIZE;i++)
		{
		
		printf("%d ",a[i]);
	}
}
void insertion_sort(int a[])
{
	int i,j,t;
	for(j=i-1;j>=0 && t<a[j];j--)
	{
		a[j+1]=a[j];
		a[j+1]=t;
	}
	printf("after sorting the array");
	
		for(i=0;i<SIZE;i++)
		{
		
		printf("%d ",a[i]);
	}
 }
 int binary_search(int a[],int e) 
 {
 	int mid,low,high;
 	low=0;high=SIZE-1;
 	while(low<=high)
 	{
 		mid=(low+high)/2;
 		if(e==a[mid])
 		return 1;
 		if(e<a[mid])
 		high=mid-1;
 		else
 		low=low=mid+1;
 	}
 	return 0;
	 }
 
 void display(int a[])
 {
 		int i;
 		printf("the enter array is\n");
		for(i=0;i<SIZE;i++)
		printf("%d  ",a[i]);
		printf("\n");
 }
 
int main()
{
	int a[SIZE],i,ch;
	printf("enter the element of the array one by one\n");
	for(i=0;i<SIZE;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
		
	}
	do{
	
	printf("enter the choice");
	printf("Enter 1 to selection sort , 2 to bubble sort, 3 to insertion sort , 4 exit\n");
	scanf("%d",&ch);
	switch(ch)		
	{
		case 1:
			selection(a);
			
			break;
			case 2:
			bubble_sort(a);
			
			break;
			case 3:				
			insertion_sort(a);
			
			break;
		
			default:
				printf("wrong choice");				
			
			
	}}while(ch!=4);
}


