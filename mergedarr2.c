#include <stdio.h>

void mergedArrays(int a[], int n, int b[], int m, int c[], int *size)
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            if (k == 0 || c[k - 1] != a[i])  
                c[k++] = a[i];
            i++;
        }
        else if (a[i] > b[j])
        {
            if (k == 0 || c[k - 1] != b[j])
                c[k++] = b[j];
            j++;
        }
        else
        {
            if (k == 0 || c[k - 1] != a[i])
                c[k++] = a[i];
            i++;
            j++;
        }
    }

    while (i < n)
    {
        if (k == 0 || c[k - 1] != a[i])
            c[k++] = a[i];
        i++;
    }

    while (j < m)
    {
        if (k == 0 || c[k - 1] != b[j])
            c[k++] = b[j];
        j++;
    }

    *size = k; 
}

int main()
{
	int i;
    int a[] = {10, 15, 17, 25, 37};
    int b[] = {7, 10, 12, 23, 37, 46, 59};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int c[n + m]; 
    int size = 0;

    mergedArrays(a, n, b, m, c, &size);

    printf("Merged array without duplicates:\n");
    for (i = 0; i < size; i++)
        printf("%d ", c[i]);
    printf("\n");

    return 0;
}

