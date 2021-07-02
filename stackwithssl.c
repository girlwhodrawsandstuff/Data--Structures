/* implementation of a stack using a single linked list */

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();

struct node {
    int data;
    struct node * next;
};

struct node * top = NULL;

void main() {
    push(2);
    pop();
}

void push(int value) {
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode -> data = value;
    newnode -> next = top;
    top = newnode;

    printf("Value added!\n");
}

void pop() {
    struct node * temp;

    if(top == NULL) {
        printf("The stack is empty!\n");
    } else {
        temp = top;
        top = top -> next;
        temp -> next = NULL;
        free(temp);
        printf("Value deleted from the stack!\n");
    }
}
