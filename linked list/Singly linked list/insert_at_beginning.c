#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("\nElement is: %d", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertatfirst(struct node *head,int data){

    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr ->next = head;
    ptr->data = data;
    return ptr;


};

void main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node *));
    struct node *first = (struct node *)malloc(sizeof(struct node *));
    struct node *second = (struct node *)malloc(sizeof(struct node *));
    struct node *third = (struct node *)malloc(sizeof(struct node *));

    head->data = 100;
    head->next = first;

    first->data = 200;
    first->next = second;

    second->data = 300;
    second->next = third;

    third->data = 400;
    third->next = NULL;

    int data;
    printf("Enter number which you want to insert: ");
    scanf("%d", &data);

    head = insertatfirst(head , data);  

    print(head);
}