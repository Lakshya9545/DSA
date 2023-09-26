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

// Function to delete a node at a specified position
struct Node *deleteAtPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    struct Node *temp = head;
    int count = 1;

    // Traverse to the node at the specified position
    while (count < position && temp->next != head)
    {
        temp = temp->next;
        count++;
    }

    // If the position is invalid
    if (count != position)
    {
        printf("Position exceeds the length of the list. Cannot delete.\n");
        return head;
    }

    // Adjust pointers to delete the node
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    // If deleting the head node, update the head
    if (temp == head)
    {
        head = temp->next;
    }

    // Free the node
    free(temp);

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

    int position;
    printf("Enter the position of the element you want to delete: ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);

    printf("Doubly Linked list after deletion:\n");
    printList(head);

    return 0;
}
