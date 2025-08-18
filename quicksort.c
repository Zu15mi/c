#include<stdio.h>
#include<stdlib.h>

int partition(int a[], int, int);
void quicksort(int a[], int, int);
void printArray(int a[], int);
 
int main()
{
	printf("Enter SIZE: ");
	int n;
	scanf("%d", &n);
	if(n<=0) {
		printf("\nInvalid array SIZE.");
		return 1;
	}
	int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int i;
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &array[i]);
    }
    printf("Original array:\n");
    printArray(array, n);

    quickSort(array, 0, n - 1);

    printf("Sorted array:\n");
    printArray(array, n);

    free(array);
    return 0;
}

void swap(int* a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int l, int h)
{
	int i,j;int pivot;
	pivot = a[h];
	i=l-1;
	for(j=l; j<h; j++)
	if(a[j]<=pivot) {
	i++;
	swap(&a[i], &a[j]);
}
swap(&a[i+1], &a[h]);
return i+1;
}

void quicksort(int a[], int l, int h)
{
	int p;
	if(l<h)
	{
		p = partiton(a, l, h);
		quicksort(a, l, p-1);
		quicksort(a, p+1, h);
	}
}

void printArray(int a[], int SIZE) 
{
	int i;
	 for (i = 0; i < SIZE; i++)
        printf("%d ", a[i]);
    printf("\n");
}

