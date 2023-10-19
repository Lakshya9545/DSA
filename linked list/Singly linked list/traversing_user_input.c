#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node
{
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and print the linked list
void traverseLinkedList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int n, data;

    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for element %d: ", i + 1);
        scanf("%d", &data);

        struct Node *newNode = createNode(data);

        if (head == NULL)
        {
            // If the linked list is empty, set the new node as the head
            head = newNode;
        }
        else
        {
            // Otherwise, insert the new node at the end
            struct Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Print the linked list
    printf("Linked List: ");
    traverseLinkedList(head);

    return 0;
}
