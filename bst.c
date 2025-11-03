#include <stdio.h>
#include <stdlib.h>


struct node 
{
    int data;
    struct node *left, *right;
};


struct node* createNode(int value) 
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct node* insert(struct node* root, int value) 
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct node* root) 
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root) 
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) 
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() 
{
    struct node* root = NULL;
    int n, value;

    printf("Enter number of nodes to insert: "); //71,43,66,90,88,14,85
    scanf("%d", &n);
    int i;
	for ( i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal   (Left, Root, Right):\n");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal  (Root, Left, Right):\n");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal (Left, Right, Root):\n");
    postorder(root);
    printf("\n");

    return 0;
}

