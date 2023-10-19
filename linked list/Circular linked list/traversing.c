#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print(struct node *head) {
    struct node *ptr = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        printf("Element is: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head); // Traverse until we reach the head again

}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));

    head->data = 100;
    head->next = first;

    first->data = 200;
    first->next = second;

    second->data = 300;
    second->next = third;

    third->data = 400;
    third->next = head; // Make it circular

    print(head);

    return 0;
}
