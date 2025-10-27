#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int key;
    struct List * next;
} NODE;

NODE *head = NULL;

NODE * create(int k)
{
    NODE *x = (NODE*)malloc(sizeof(NODE));
    x->key = k;
    x->next = NULL;
    return x;
}

void insertLast(int k)
{
    NODE *p = create(k), *q = head;
    if (!head)
    {
        head = p;
        return;
    }
    while (q->next)
        q = q->next;

    q->next = p;
}

void insertFirst(int k)
{
    NODE *p = create(k);
    p->next = head;
    head = p;
}

void insertPosition(int k, int pos)
{
    NODE *p = create(k), *q = head;
    int i;

    if (pos == 1) // Insert at head
    {
        insertFirst(k);
        return;
    }

    for (i = 1; i < pos - 1; i++)
    {
        if (q == NULL)
        {
            printf("Position out of bounds\n");
            free(p);
            return;
        }
        q = q->next;
    }

    if (q == NULL)
    {
        printf("Position out of bounds\n");
        free(p);
        return;
    }

    p->next = q->next;
    q->next = p;
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete\n");
        return;
    }
    NODE *temp = head;
    head = head->next;
    free(temp);
}

void deleteLast()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    NODE *p = head;
    while (p->next->next != NULL)
        p = p->next;

    free(p->next);
    p->next = NULL;
}

void deletePosition(int pos)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete\n");
        return;
    }

    if (pos == 1)
    {
        deleteFirst();
        return;
    }

    NODE *p = head;
    int i;
    for (i = 1; i < pos - 1; i++)
    {
        if (p->next == NULL)
        {
            printf("Position out of bounds\n");
            return;
        }
        p = p->next;
    }

    if (p->next == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    NODE *temp = p->next;
    p->next = temp->next;
    free(temp);
}

void display()
{
    NODE *p = head;
    if (p == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (p)
    {
        printf("%d\t", p->key);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int ch, k, pos;
    do
    {
        printf("1.create()\n");
        printf("2.insertLast()\n");
        printf("3.insertFirst()\n");
        printf("4.insertPosition()\n");
        printf("5.deleteFirst()\n");
        printf("6.deleteLast()\n");
        printf("7.deletePosition()\n");
        printf("8.Exit\n");
        printf("Choice = ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value of 'k' = ");
            scanf("%d", &k);
            create(k);
            break;

        case 2:
            printf("Enter value of 'k' = ");
            scanf("%d", &k);
            insertLast(k);
            display();
            break;

        case 3:
            printf("Enter value of 'k' = ");
            scanf("%d", &k);
            insertFirst(k);
            display();
            break;

        case 4:
            printf("Enter value of 'k' = ");
            scanf("%d", &k);
            printf("Enter pos = ");
            scanf("%d", &pos);
            insertPosition(k, pos);
            display();
            break;

        case 6:
            deleteFirst();
            display();
            break;

        case 7:
            deleteLast();
            display();
            break;

        case 8:
            printf("Enter pos = ");
            scanf("%d", &pos);
            deletePosition(pos);
            display();
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    } while (ch != 5);
    return 0;
}

