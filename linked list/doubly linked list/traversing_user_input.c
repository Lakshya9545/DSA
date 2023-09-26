#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
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
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to traverse and print the doubly linked list forward
void traverseLinkedListForward(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to traverse and print the doubly linked list backward
void traverseLinkedListBackward(struct Node *tail)
{
    if (tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = tail;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int n, data;

    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
        if (tail == NULL)
        {
            tail = head; // Initialize tail with the first node
        }
    }

    printf("Doubly Linked List (Forward):\n");
    traverseLinkedListForward(head);

    printf("Doubly Linked List (Backward):\n");
    traverseLinkedListBackward(tail);
  
        // Free the allocated memory for the linked list
        struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
