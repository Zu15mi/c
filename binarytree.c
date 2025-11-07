#include <stdio.h>
#include <stdlib.h>
typedef struct Tree
{
	int key;
	struct Tree *left, *right;
}NODE;

NODE *root=NULL;

void create(int k)
{
	NODE *p=(NODE *)malloc(sizeof(NODE));
	NODE *q=root, *r;
	int ch;
	p->key=k;
	p->left=p->right=NULL;
	if(!root)
	{
		root=p;
		return;
	}
	while(q)
	{
		r=q;
		printf("%d will be at the left subtree or at the right subtree of %d (1/0): \n", k, r->key);
		scanf("%d", &ch);
		if(ch)
			q=q->left;
		else
			q=q->right;
	}
	if(ch)
		r->left=p;
	else
		r->right=p;
}

void inorder(NODE *r)
{
	if(r)
	{
		inorder(r->left);
		printf("%d\t", r->key);
		inorder(r->right);
	}
}
int main()
{
	create(71);
	create(43);
	create(90);
	create(88);
	create(66);
	create(85);
	create(14);
	printf("The binary tree is: \n");
	inorder(root);
	return 0;
}
