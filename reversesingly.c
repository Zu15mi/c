#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int key;
    struct List* next;
} NODE;

NODE* createNode(int val)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->key = val;
    newNode->next = NULL;
    return newNode;
}

NODE* appendNode(NODE* head, int val)
{
    NODE* newNode = createNode(val);
    if (head == NULL)
        return newNode;

    NODE* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

NODE* reverseList(NODE* head)
{
    NODE* prev = NULL;
    NODE* current = head;
    NODE* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(NODE* head)
{
    NODE* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    NODE* head = NULL;
    int n,i, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        head = appendNode(head, val);
    }

    printf("Original list:\n");
    printList(head);

    head = reverseList(head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}

