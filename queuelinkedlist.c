#include <stdio.h>
#include <stdlib.h>

void addElement();

struct node {
    int data;
    struct node * next;
};

struct node * front = 0;
struct node * rear = 0;

void main() {
    addElement(5);
}

void addElement(int value) {
    struct node * newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> next = 0;

    if(front == 0 && rear == 0) {
        front = rear = newNode;
        printf("Element added!\n");
    } else {
        rear -> next = newNode;
        rear = newNode;
        printf("Element added!\n");
    }
}