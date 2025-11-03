#include <stdio.h>
#include <stdlib.h>


typedef struct node 
{
    int e;
    struct node *left, *right;
}NODE;


NODE* createNode(int k) 
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->e = k;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct node* insert(struct node* root, int k) 
{
    if (root == NULL)
        return createNode(k);

    if (k < root->e)
        root->left = insert(root->left, k);
    else if (k > root->e)
        root->right = insert(root->right, k);

    return root;
}

NODE* findMin(NODE* root) 
{
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

NODE* inorderSuccessor(NODE* root, NODE* target) 
{
    NODE* successor = NULL;

    while (root != NULL) 
	{
        if (target->e < root->e) 
		{
            successor = root;
            root = root->left;
        }
        else if (target->e > root->e)
            root = root->right;
        else
            break;
    }
if (target->right != NULL)
        successor = findMin(target->right);

    return successor;
}

NODE* search(NODE* root, int key) 
{
    if (root == NULL || root->e == key)
        return root;
    if (key < root->e)
        return search(root->left, key);
    return search(root->right, key);
}

int main() 
{
    NODE* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 2);
    insert(root, 15);
    insert(root, 35);

    int key;
    printf("Enter key to find its inorder successor: ");
    scanf("%d", &key);

    NODE* target = search(root, key);
    if (target == NULL) {
        printf("Key not found in BST.\n");
        return 0;
    }

    NODE* successor = inorderSuccessor(root, target);
    if (successor != NULL)
        printf("Inorder successor of %d is %d\n", key, successor->e);
    else
        printf("%d has no inorder successor.\n", key);

    return 0;
}
