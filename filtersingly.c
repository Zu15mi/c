/* create a singly linked list which nodes have values 9, 7, 12, 10, 6.
 now create another singly linked list which will only have the nodes with values greater than
  equals to 10 of the first list. 
 */
 
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

NODE* filterList(NODE* head)
{
    NODE* filteredHead = NULL;

    NODE* temp = head;
    while (temp != NULL)
    {
        if (temp->key >= 10)
        {
            filteredHead = appendNode(filteredHead, temp->key);
        }
        temp = temp->next;
    }
    return filteredHead;
}

int main()
{
	int i;
    NODE* list1 = NULL;
    int values[] = {9, 7, 12, 10, 6};
    int n = sizeof(values) / sizeof(values[0]);

    for (i = 0; i < n; i++)
    {
        list1 = appendNode(list1, values[i]);
    }

    printf("Original list:\n");
    printList(list1);

    NODE* list2 = filterList(list1);

    printf("Filtered list (values >= 10):\n");
    printList(list2);

    return 0;
}

