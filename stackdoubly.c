#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} NODE;

NODE *head = NULL;

void insertFirst(int val)
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

int deleteFirst()
{
    if (head == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    NODE *temp = head;
    int val = temp->data;

    head = head->next;
    if (head != NULL)
        head->prev = NULL;

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
        printf("Stack is empty\n");
        return;
    }
    NODE *temp = head;
    printf("Stack elements (top to bottom): ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch, val;

    do
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value to push: ");
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

            case 5:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice, try again\n");
        }
    } while(ch != 5);

    return 0;
}

