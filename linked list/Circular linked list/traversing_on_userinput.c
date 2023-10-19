#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct node **head, int data)
{
    struct node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head; // Point to itself to create a circular link
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void print(struct node *head)
{
    struct node *current = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    do
    {
        printf("%d\n", current->data);
        current = current->next;
    } while (current != head);
}

int main()
{
    struct node *head = NULL;
    int choice, data;

    do
    {
        printf("1. Insert an element\n");
        printf("2. Print the circular linked list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert(&head, data);
            break;
        case 2:
            printf("Circular Linked List:\n");
            print(head);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}
