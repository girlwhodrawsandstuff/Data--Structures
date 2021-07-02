/* implementation of a stack using a single linked list */

#include <stdio.h>
#include <stdlib.h>

void push();

struct node {
    int data;
    struct node * next;
};

struct node * top = NULL;

void main() {
    push(2);
}

void push(int value) {
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode -> data = value;
    newnode -> next = top;
    top = newnode;

    printf("Value added!\n");
}
