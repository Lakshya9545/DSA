#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define MAX as a constant (adjust the size as needed)
int stack_arr[MAX];
int top = -1;

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack_arr[top] = data;
}

int main()
{
    int data;
    printf("Enter the elements to push into the stack: ");
    for (int i = 0; i < MAX; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        push(data);
    }

    printf("Stack contents: ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");

    return 0;
}
