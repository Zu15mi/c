 /* we have 2 array (a, b) of elements which are already sorted, now take another array c 
 which will contain all the elements of a and b in sorted format and c will be the merged
 array of a and b. */
 
 #include <stdio.h>

void mergedArrays(int a[], int n, int b[], int m, int c[])
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < n)
        c[k++] = a[i++];

    while (j < m)
        c[k++] = b[j++];
}

int main()
{
	int i;
    int a[] = {10, 15, 17, 25, 37};
    int b[] = {7, 10, 12, 23, 37, 46, 59};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int c[n + m]; 

    mergedArrays(a, n, b, m, c);

    printf("Merged array:\n");
    for (i = 0; i < n + m; i++)
        printf("%d ", c[i]);
    printf("\n");

    return 0;
}

