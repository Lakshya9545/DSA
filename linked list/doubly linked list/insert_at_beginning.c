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

struct Node *insertAtFirst(struct Node *head, int data)
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

    // Link the last node to newNode
    lastNode->next = newNode;
    newNode->prev = lastNode;

    // Link newNode to the head node and update head
    newNode->next = head;
    head->prev = newNode;

    return newNode; // Return the updated head
}

int main()
{
    struct Node *head = NULL;

    // Create a circular doubly linked list with initial elements
    head = insertAtFirst(head, 4);
    head = insertAtFirst(head, 3);
    head = insertAtFirst(head, 6);
    head = insertAtFirst(head, 1);

    printf("\nCircular Doubly Linked list before insertion\n\n");
    linkedListTraversal(head);

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
        head = insertAtFirst(head, array[i]);
    }

    printf("\nCircular Doubly Linked list after insertion\n\n");
    linkedListTraversal(head);

    // Clean up memory
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
