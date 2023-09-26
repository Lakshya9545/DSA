#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *current = head;

    if (head == NULL)
    {
        printf("Doubly linked list is empty.\n");
        return;
    }

    printf("Doubly Linked List (Forward): ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    // Traverse in reverse order
    printf("Doubly Linked List (Reverse): ");
    current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the doubly linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Assign data to each node
    head->data = 4;
    second->data = 3;
    third->data = 6;
    fourth->data = 1;

    // Link nodes forward
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    // Link nodes backward
    head->prev = NULL;
    second->prev = head;
    third->prev = second;
    fourth->prev = third;

    linkedListTraversal(head);

    return 0;
}
