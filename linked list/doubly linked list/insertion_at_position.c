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
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node *insertAtPosition(struct Node *head, int data, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position < 1)
    {
        printf("Invalid position. Position should be >= 1.\n");
        free(newNode);
        return head;
    }

    if (position == 1)
    { // Insert at the beginning
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        return newNode; // The new node becomes the new head
    }

    // Traverse to the node just before the desired position
    struct Node *current = head;
    int currentPosition = 1;
    while (currentPosition < position - 1 && current != NULL)
    {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL)
    {
        printf("Position exceeds the length of the list.\n");
        free(newNode);
        return head;
    }

    // Insert the new node
    newNode->next = current->next;
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;

    // Create a doubly linked list with initial elements
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->prev = NULL;
    head->next = second;

    second->data = 3;
    second->prev = head;
    second->next = third;

    third->data = 6;
    third->prev = second;
    third->next = fourth;
    fourth->data = 1;
    fourth->prev = third;
    fourth->next = NULL;

    printf("Doubly Linked list before insertion\n");
    linkedListTraversal(head);

    int data, position;
    printf("\nEnter the element you want to insert: ");
    scanf("%d", &data);
    printf("Enter the position where you want to insert: ");
    scanf("%d", &position);

    head = insertAtPosition(head, data, position);

    printf("\nDoubly Linked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}
