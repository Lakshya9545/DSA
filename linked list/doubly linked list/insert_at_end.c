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
    printf("Doubly Linked List: ");
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL)
    { // If the list is empty, make newNode the only node
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    // Find the last node in the linked list
    struct Node *lastNode = head->prev;

    // Link the last node and newNode
    lastNode->next = newNode;
    newNode->prev = lastNode;

    // Link the newNode and head
    newNode->next = head;
    head->prev = newNode;

    return head; // Return the updated head
}

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;

    // Allocate memory for nodes in the doubly linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Initialize pointers to NULL
    head->next = NULL;
    head->prev = NULL;
    second->next = NULL;
    second->prev = NULL;
    third->next = NULL;
    third->prev = NULL;
    fourth->next = NULL;
    fourth->prev = NULL;

    // Assign data to each node
    head->data = 4;
    second->data = 3;
    third->data = 6;
    fourth->data = 1;

    // Link nodes forward
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    // Link nodes backward
    head->prev = fourth;
    second->prev = head;
    third->prev = second;
    fourth->prev = third;

    int a;
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &a);

    int array[a];
    printf("Enter your array elements\n");

    for (int i = 0; i < a; i++)
    {
        printf("Array element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < a; i++)
    {
        head = insertAtEnd(head, array[i]);
    }

    printf("\nCircular Doubly Linked List after insertion\n");
    linkedListTraversal(head);

    // Clean up memory
    free(second);
    free(third);
    free(fourth);
    struct Node *current = head->next;
    while (current != head)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(head);

    return 0;
}
