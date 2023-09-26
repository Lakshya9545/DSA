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

struct node *insertatEnd(struct node *head, int data)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;
    struct node *p =head;
 
    while (p->next !=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    

    return head;
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
printf("Enter the element which you want to insert at the end: ");
scanf("%d",&data);

    head = insertatEnd(head, data);   
    print(head);
}