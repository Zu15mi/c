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
		if(k<r->key)
			q=q->left;
		else
			q=q->right;
	}
	if(k<r->key)
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
void searchInorderSuccessor(NODE* r, int k)
{
	if(r)
	{
		if(r->key!=k)
		{
			if(r->key>k)
				searchInorderSuccessor(r->left,k);
			else
				searchInorderSuccessor(r->right,k);
		}
		printf("%d", r->key);
	}
	
}
int main()
{
	int k;
	create(71);
	create(43);
	create(90);
	create(22);
	create(66);
	create(75);
	create(95);
	printf("The binary tree is: \n");
	inorder(root);
	printf("Enter the key:\n");
	scanf("%d", &k);
	searchInorderSuccessor(root,k);
	return 0;
}
