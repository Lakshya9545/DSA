#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
    struct Node *node = newNode(data);
    node->next = stack->top;
    stack->top = node;
    printf("Pushed %d onto the stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1; // Return an error value
    }
    struct Node *temp = stack->top;
    int popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1; // Return an error value
    }
    return stack->top->data;
}

// Function to display the stack elements
void display(struct Stack *stack)
{
    struct Node *current = stack->top;
    printf("Stack contents: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;

    int choice, element;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an element to push: ");
            scanf("%d", &element);
            push(stack, element);
            break;
        case 2:
            printf("Popped item: %d\n", pop(stack));
            break;
        case 3:
            printf("Peek: %d\n", peek(stack));
            break;
        case 4:
            display(stack);
            break;
        case 5:
            free(stack);
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
