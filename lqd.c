#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} NODE;

NODE *head = NULL;
NODE *tail = NULL;  

void insertLast(int val)
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int deleteFirst()
{
    if (head == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    NODE *temp = head;
    int val = temp->data;

    head = head->next;
    if (head == NULL)
    {
        tail = NULL;
    }
    else
    {
        head->prev = NULL;
    }

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
    return head->data;
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
    NODE *temp = head;
    printf("Queue elements (front to rear): ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, val;

    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                insertLast(val); 
                break;

            case 2:
                val = deleteFirst(); 
                if (val != -1)
                    printf("Dequeued value: %d\n", val);
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
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, try again\n");
        }

    } while(choice != 5);

    return 0;
}

