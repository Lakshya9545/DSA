#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue()
{
    int data;
    struct node *temp;
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    temp = front;
    front = front->next;
    data = temp->data;
    free(temp);
    return data;
}

void display()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch, data;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data to be enqueued: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            data = dequeue();
            if (data != -1)
            {
                printf("Dequeued element: %d\n", data);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
