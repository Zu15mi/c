#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int key;
    struct List * next;
} NODE;

NODE *head = NULL;

void insertLast(int k)
{
    NODE *p = (NODE*)malloc(sizeof(NODE));
    if (!p)
    {
        printf("Memory allocation failed\n");
        return;
    }
    p->key = k;
    p->next = NULL;

    if (head == NULL)
    {
        head = p;
        return;
    }

    NODE *q = head;
    while (q->next != NULL)
        q = q->next;
    q->next = p;
}

int deleteFirst()
{
    if (head == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    NODE *temp = head;
    int val = temp->key;
    head = head->next;
    free(temp);
    return val;
}

int peek()
{
    if (head == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return head->key;
}

int isEmpty()
{
    return head == NULL;
}

void display()
{
    if (head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    NODE *p = head;
    printf("Queue elements (front to rear): ");
    while (p != NULL)
    {
        printf("%d\t", p->key);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int ch, val;

    do
    {
        printf("\n1.insertLast\n2.deleteFirst\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value to insertLast: ");
                scanf("%d", &val);
                insertLast(val);
                break;

            case 2:
                val = deleteFirst();
                if (val != -1)
                    printf("deleteFirst value: %d\n", val);
                break;

            case 3:
                val = peek();
                if (val != -1)
                    printf("Front element: %d\n", val);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice, try again\n");
        }

    } while(ch != 5);

    return 0;
}

