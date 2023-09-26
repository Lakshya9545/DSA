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
    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *deleteFirstNode(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete.\n");
        return NULL;
    }

    struct Node *newHead = head->next;
    struct Node *tail = head->prev;

    // Update the next pointer of the tail node
    tail->next = newHead;
    // Update the previous pointer of the new head
    newHead->prev = tail;

    free(head);
    printf("First node deleted successfully.\n");

    return newHead;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;
    head->prev = fourth; // Update the previous pointer of the head node

    // Link second and third nodes
    second->data = 3;
    second->next = third;
    second->prev = head; // Update the previous pointer of the second node

    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;
    third->prev = second; // Update the previous pointer of the third node

    // Link fourth and head nodes
    fourth->data = 1;
    fourth->next = head;
    fourth->prev = third; // Update the previous pointer of the fourth node

    printf("Original doubly linked list:\n");
    linkedListTraversal(head);

    head = deleteFirstNode(head);

    printf("Doubly linked list after deleting the first node:\n");
    linkedListTraversal(head);

    return 0;
}
