#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void insertBegin(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void deleteNode(int key) {
    if (head == NULL)
        return;

    struct Node *curr = head, *prev = NULL;

    if (head->data == key) {
        struct Node *last = head;
        while (last->next != head)
            last = last->next;

        if (head->next == head) { 
            free(head);
            head = NULL;
            return;
        }

        last->next = head->next;
        free(head);
        head = last->next;
        return;
    }

    do {
        prev = curr;
        curr = curr->next;
    } while (curr != head && curr->data != key);

    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertBegin(5);
    display();

    printf("\nDeleting 10...\n");
    deleteNode(10);
    display();

    printf("\nDeleting head (5)...\n");
    deleteNode(5);
    display();

    return 0;
}

