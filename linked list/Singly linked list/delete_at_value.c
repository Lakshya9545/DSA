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

struct node *deleteatvalue(struct node *head,int value)
{

    struct node *p = head;
    struct node *q = head->next;
   while(q->data!= value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    


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

    int value;
    printf("Enter the index of element which you want to delete \n(Note: use deletion at beginning to delete first element)\n  :  \t");
    scanf("%d", &value);

    head = deleteatvalue(head, value);
    print(head);
}