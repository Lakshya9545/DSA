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

struct node *deleteatlast(struct node *head)
{

    struct node *p = head;
    struct node *q = head->next;
   while (q->next != NULL)
   {
   p =  p->next;
   q =  q->next;

   }
   
    p->next = NULL;
    free(q);

    return head;
}

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

  

    head = deleteatlast(head);
    print(head);
}