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

struct node *deleteatindex(struct node *head, int index)
{
    
struct node *p = head;
struct node *q = head->next;
for (int i = 0; i < index-1; i++)
{
    p = p->next;
    q = q->next;

}
p->next = q->next;
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

    int index;
    printf("Enter the index of element which you want to delete \n(Note: use deletion at beginning to delete first element)\n  :  \t");
    scanf("%d",&index);

    head = deleteatindex(head, index);
    print(head);
}