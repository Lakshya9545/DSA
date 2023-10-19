#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print(struct node *start)
{
    struct node *ptr = start;
    if (start == NULL)
    {
        printf("List is empty.");
        return;
    }
    do
    {
        printf("Element is: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
}

struct node *insertAtBeginning(struct node *start, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = start;

    struct node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    // Update the start pointer to the new first node
    start = newNode;

    return start;
}

int main()
{
    struct node *start = NULL;

    int data;
    printf("Enter the number you want to insert: ");
    scanf("%d", &data);

    start = insertAtBeginning(start, data);

    print(start);

    return 0;
}
