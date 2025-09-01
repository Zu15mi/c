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
    for (i = 1; i < pos - 1; i++)
        q = q->next;

    p->next = q->next;
    q->next = p;
}

void display()
{
    NODE *p = head;
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
        printf("5.Exit\n");
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

        case 5:
            return 0;
        }
    } while (ch != 5);
    return 0;
}

