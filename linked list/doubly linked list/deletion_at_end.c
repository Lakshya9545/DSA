#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to delete the last node
struct Node *deleteAtEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    struct Node *lastNode = head->prev;

    if (head->next == head)
    {
        // If there's only one node in the list
        free(head);
        return NULL; // Return NULL as the list is now empty
    }

    // Adjust pointers to delete the last node
    lastNode->prev->next = head;
    head->prev = lastNode->prev;

    // Free the last node
    free(lastNode);

    return head;
}

// Function to print the doubly linked list
void printList(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = createNode(4);
    second = createNode(3);
    third = createNode(6);
    fourth = createNode(1);

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

    printf("Doubly Linked list before deletion:\n");
    printList(head);

    head = deleteAtEnd(head);

    printf("Doubly Linked list after deletion:\n");
    printList(head);

    return 0;
}
