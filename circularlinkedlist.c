#include<stdio.h>
#include<stdlib.h>
typedef struct List
{
	int key;
	struct List *next;
	
}NODE;
NODE *head=NULL;
NODE *create(int k)
{
	NODE *x=(NODE*)malloc(sizeof(NODE));
	x->key=k;
	x->next=NULL;
	return x;
	
}
void insertLast(int k)
{
	NODE *p=create(k),*q=head;
    if (!head) {        // empty list
        head = p;
        head->next = head;
        return;
    }
	
	if(!head)
	{
		head=p;
		head->next=head;
		return;
	}
	while(q->next!=head)
	q=q->next;
	q->next=p;
	p->next=head;
}
void insertFirst(int k)
{
	NODE *p=create(k),*q=head;
	if (!head) {           // empty list
        head = p;
        head->next = head; // circular link
        return;
    }
	
	while(q->next!=head)
	{
		q=q->next;
	}
	p->next=head;
	q->next=p;
	head=p;
}
void insertPosition(int k,int pos)
{
	NODE *p=create(k),*q=head;
	int i;
	for(i=1;i<pos-1;i++)
	{
		q=q->next;
	}
	p->next=q->next;
	q->next=p;
}
int deleteFirst()
{
	if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }

	NODE *p=head,*q=head;
	int k=p->key;
	if(head->next==head)
	{
		head=NULL;
		free(p);
		return k;
	}
	while(q->next!=head)
	q=q->next;
	q->next=head->next;
	head=head->next;
	free(p);
	return k;
}
int deleteLast()
{
	NODE *p=head;
	int k;
	while(p->next->next!=head)
	p=p->next;
	k=p->next->key;
	p->next->next=NULL;
	free(p->next);
	p->next=head;
	return k;
}
int deletePosition(int pos)
{
	NODE *p=head,*q;
	int k,i;
	for(i=1;i<pos-1;i++)
	{
		p=p->next;
	}
	k=p->next->key;
	q=p->next;
	p->next=q->next;
	q->next=NULL;
	free(q);
	return k;
}
void display()
{
	NODE *p=head;
	do
	{
		printf("%d\t",p->key);
		p=p->next;
	}
	while(p!=head);
	printf("\n");
}
int main()
{
	while(1)
	{
		int ch,e,pos;
		printf("Enter 1 to insert element at first\n");
		printf("Enter 2 to insert element at last\n");
		printf("Enter 3 to insert element at any position\n");
		printf("Enter 4 to delete element at first \n");
		printf("Enter 5 to delete element at last \n");
		printf("Enter 6 to delete element at any position \n");
		printf("Enter 7 to display the CIRCULAR LINKED LIST\n");
		printf("Enter 8 to exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("Enter elemment to insert\n");
			scanf("%d",&e);
			insertFirst(e);
			break;
		case 2:
			printf("Enter element to insert\n");
			scanf("%d",&e);
			insertLast(e);
			break;
		case 3:
			printf("Enter element to insert\n");
			scanf("%d",&e);
			printf("Enter position\n");
			scanf("%d",&pos);
			insertPosition(e,pos);
			break;
		case 4:
			deleteFirst();
			break;
		case 5:
			deleteLast();
			break;
		case 6:
			printf("Enter the position\n");
			scanf("%d",&pos);
			deletePosition(pos);
			break;
		case 7:
			display();
			break;
		case 8:
			printf("Exiting\n");
			exit(1);
		default:
			printf("Wrong choice\n");
			
	
			
		}
	}
}

