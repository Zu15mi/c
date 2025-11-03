#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node 
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE* createNode(int value) 
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


NODE* insert(NODE *root, int value) 
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(NODE *root, int arr[], int *index) 
{
    if (root == NULL)
        return;

    inorder(root->left, arr, index);
    arr[(*index)++] = root->data;
    inorder(root->right, arr, index);
}

void findSuccessor(NODE *root, int key) 
{
    int arr[MAX], n = 0;
    inorder(root, arr, &n);  

    int found = 0;
    printf("\nInorder sequence: ");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n; i++) 
	{
        if (arr[i] == key) 
		{
        	
            found = 1;
            if (i + 1 < n)
                printf("\nInorder successor of %d is %d\n", key, arr[i + 1]);
            else
                printf("\n%d has no inorder successor.\n", key);
            break;
        }
    }

    if (!found)
        printf("\nKey %d not found in the tree.\n", key);
}

int main() {
    NODE *root = NULL;
    int key;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 2);
    insert(root, 15);
    insert(root, 35);

    printf("Enter key to find its inorder successor: ");
    scanf("%d", &key);

    findSuccessor(root, key);

    return 0;
}

