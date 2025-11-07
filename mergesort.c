#include <stdio.h>

void mergeSort(int a[], int n)
{
	int s=1,l1,l2,u1,u2,i,j;
	int t[n];
	while(s<n)
	{
		l1=0;
		int k=0;
		while(l1+s<n)
		{
			l2=l1+s;
			u1=l2-1;
			u2=(u1+s)<n?u1+s:n-1;
			for(i=l1,j=l2;i<=u1 && j<=u2;k++)
			{
				if(a[i]<a[j])
					t[k]=a[i++];
				else
					t[k]=a[j++];
			}
			while(i<=u1)
				t[k++]=a[i++];
			while(j<=u2)
				t[k++]=a[j++];
			l1=u2+1;
		}
		for(i=l1;i<n;i++)
			t[k++]=a[i];
		for(i=0;i<n;i++)
			a[i]=t[i];
		s*=2;
	}
}
void display(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
int main()
{
	int n,i,a[50];
	printf("Enter the number of elements: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
		scanf("\n%d",&a[i]);
	mergeSort(a,n);
	printf("The sorted array is: \n");
	display(a,n);
	return 0;
}
