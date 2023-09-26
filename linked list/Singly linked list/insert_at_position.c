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


struct node *insertatindex(struct node *head, int data,int index)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    struct node *p = head;
    int i = 0;
    while (i != index-1)
    {
        p=p->next;
        i++;
    }
    
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
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
    int data,index;
    
    printf("Enter the Number which you want to insert: \n");
    scanf("%d", &data);
        printf("Enter the Index where you want to insert: \n");
    scanf("%d", &index);
        head = insertatindex(head, data ,index );
    print(head);


}