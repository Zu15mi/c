#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
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
 	
	}
	int main()
	{
		int a[SIZE],i,k;
		printf("enter the element of the array one by one");
		for(i=0;i<SIZE;i++)
		{
			printf("a[%d]:",i);
			scanf("%d",&a[i]);
			
		}
		printf("enter the elment to search");
		scanf("%d ",&k);
		
		i=binary_search(a,k);
		if(i==1)
		{
			printf("the element is not present");
			exit(0);
		}
		printf("the element is  present");
		}
	
	
