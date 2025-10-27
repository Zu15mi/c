#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
	int key;
	struct List *prev;
	struct List *next;
}NODE;

NODE *head=NULL;

NODE *create(int k)
{
	NODE *x=(NODE*)malloc(sizeof(NODE));
	x->key=k;
	x->prev=NULL;
	x->next=NULL;
	return x;
}

void insertFirst(int k)
{
	NODE *y=create(k);
	if(head==NULL)
	{
	head=y;
	return;
	}
	y->next=head;
	head->prev=y;
	head=y;
}

void insertLast(int k)
{
	 NODE *y=create(k);
    if (head==NULL) 
	{
        head=y;
        return;
    }
    NODE *z=head;
    while (z->next!=NULL)
        z=z->next;

    z->next=y;
    y->prev=z;
}

void insertPosition(int k, int pos) 
{
    if (pos==1) 
	{
        insertFirst(k);
        return;
    }

    NODE *y=create(k);
    NODE *z=head;
    int i;
    for (i=1; i<pos-1 &&z!=NULL; i++)
        z = z->next;

    if (z==NULL) 
	{
        printf("Position out of bounds!\n");
        free(y);
        return;
    }

    y->next = z->next;
    y->prev = z;
    if (z->next != NULL)
        z->next->prev = y;
    z->next = y;
}

void deleteFirst()
{
	if(head=NULL)
	{
		printf("List is empty.\n");
		return;
	}
	NODE *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

void deleteLast()
{
	if (head == NULL) 
	{
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) 
	{
        free(head);
        head = NULL;
        return;
    }

    NODE *y = head;
    while (y->next != NULL)
        y = y->next;

    y->prev->next = NULL;
    free(y);
}

void deletePosition(int pos)
{
	if (head == NULL) 
	{
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) 
	{
        deleteFirst();
        return;
    }

    NODE *y = head;
    int i;
    for (i = 1; i < pos && y != NULL; i++)
        y = y->next;

    if (y == NULL) 
	{
        printf("Position out of bounds!\n");
        return;
    }

    if (y->prev != NULL)
        y->prev->next = y->next;
    if (y->next != NULL)
        y->next->prev = y->prev;

    free(y);
}

void displayForward() 
{
    NODE *y = head;
    if (y == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List (forward): ");
    while (y != NULL) {
        printf("%d\t", y->key);
        y = y->next;
    }
    printf("\n");
}

void displayBackward() 
{
    NODE *y = head;
    if (y == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (y->next != NULL)
        y = y->next;

    printf("List (backward): ");
    while (y != NULL)
	{
        printf("%d\t", y->key);
        y = y->prev;
    }
    printf("\n");
}

int main() 
{
    int ch, k, pos;
    do 
	{
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert at position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete position\n");
        printf("7. Display forward\n");
        printf("8. Display backward\n");
        printf("9.create()\n");
        printf("10. Exit\n");
        printf("Choice = ");
        scanf("%d", &ch);

        switch (ch) 
		{
            case 1:
                printf("Enter value of 'k' = ");
                scanf("%d", &k);
                insertFirst(k);
                displayForward();
                break;

            case 2:
                printf("Enter value of 'k' = ");
                scanf("%d", &k);
                insertLast(k);
                displayForward();
                break;

            case 3:
                printf("Enter value of 'k' = ");
                scanf("%d", &k);
                printf("Enter position = ");
                scanf("%d", &pos);
                insertPosition(k, pos);
                displayForward();
                break;

            case 4:
                deleteFirst();
                displayForward();
                break;

            case 5:
                deleteLast();
                displayForward();
                break;

            case 6:
                printf("Enter position to delete = ");
                scanf("%d", &pos);
                deletePosition(pos);
                displayForward();
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            case 10:
                printf("Exiting...\n");
                return 0;
            
			case 9:
            printf("Enter value of 'k' = ");
            scanf("%d", &k);
            create(k);
            break;    
                

            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 10);
    return 0;
}

