#include <stdio.h> 
#include<stdlib.h>

int MAX;
int stack_arr[MAX];
int top = -1;

void push(int data){
    if (top == MAX-1)
    {
        printf("Stack is full");
        return;
    }
    top++;
    stack_arr[top] = data;
    
}

void main()
{
    printf("Enter the size of the stack: ");
    scanf("%d", &MAX);

    int data;
    printf("Enter the elements to push into the stack: ");
    for (int i = 0; i < MAX; i++)
    {
        int data;
        printf("Enter the element to push into the stack: ");
        scanf("%d", &data);
        push(data);
    }

    for (int i = top; i >= 0; i--){
    {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

}