/* implementation of a stack using a single linked list */

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node {
    int data;
    struct node * next;
};

struct node * top = NULL;

void main() {
    push(2);
    pop();
    push(4);
    push(16);
    display();
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

void display() {
    struct node * temp;
    
    if(top == NULL) {
        printf("The stack is empty!\n");
    } else {
        temp = top; 

        printf("The elements are:\n");

        while(temp != NULL) {
            printf("%d\n", temp -> data);
            temp = temp -> next;
        }
    }
}
