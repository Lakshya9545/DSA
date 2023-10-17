#include <stdio.h>
#include <stdlib.h>

#define n 5
int queue[n];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == n - 1)
    {
        printf("Queue is full\n");
    }
    else if (front == -1)
    {
        front++;
        rear++;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

int dequeue()
{
    int data;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    data = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return data;
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
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
