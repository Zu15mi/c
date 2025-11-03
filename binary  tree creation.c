#include <stdio.h>
#include <stdlib.h>


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


NODE* insertLevelWise(NODE *root, int value) 
{
    NODE *newNode = createNode(value);
    if (root == NULL)
        return newNode;

    NODE *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) 
	{
        NODE *temp = queue[front++];

        if (temp->left == NULL) 
		{
            temp->left = newNode;
            return root;
        } else 
		{
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) 
		{
            temp->right = newNode;
            return root;
        } else 
		{
            queue[rear++] = temp->right;
        }
    }
    return root;
}


void inorder(NODE *root) 
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(NODE *root) 
{
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE *root) 
{
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


int main() 
{
    NODE *root = NULL;
    int n, value;

    printf("Enter number of nodes: ");//71,43,66,90,88,14,85
    scanf("%d", &n);
int i;
    for (i = 1; i <= n; i++) 
	{
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        root = insertLevelWise(root, value);
    }

    printf("\n--- TREE TRAVERSALS ---\n");
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

