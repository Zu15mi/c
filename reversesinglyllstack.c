#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int key;
    struct List * next;
} NODE;

NODE *head = NULL;

void insertFirst(int k)
{
    NODE *p = (NODE*)malloc(sizeof(NODE));
    if (!p)
    {
        printf("Memory allocation failed\n");
        return;
    }
    p->key = k;
    p->next = head;
    head = p;
}

int deleteFirst()
{
    if (head == NULL)
    {
        printf("Stack Underflow\n");
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
        printf("Stack is empty\n");
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
        printf("Stack is empty\n");
        return;
    }
    NODE *p = head;
    printf("Stack elements (top to bottom): ");
    while (p)
    {
        printf("%d\t", p->key);
        p = p->next;
    }
    printf("\n");
}

void reverseList()
{
    NODE *prev = NULL;
    NODE *current = head;
    NODE *next = NULL;

    while (current != NULL)
    {
        next = current->next;   
        current->next = prev;   
        prev = current;          
        current = next;          
    }

    head = prev;  
}

int main()
{
    int ch, val;

    do
    {
        printf("\n1.insertFirst\n2.deleteFirst\n3.Peek\n4.Display\n6.Reverse\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter element to insertFirst: ");
                scanf("%d", &val);
                insertFirst(val);
                break;

            case 2:
                val = deleteFirst();
                if (val != -1)
                    printf("Popped value: %d\n", val);
                break;

            case 3:
                val = peek();
                if (val != -1)
                    printf("Top element: %d\n", val);
                break;

            case 4:
                display();
                break;

            case 6:
                reverseList();
                printf("Stack reversed successfully.\n");
                break;

            case 5:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice, try again\n");
        }
    } while (ch != 5);

    return 0;
}

