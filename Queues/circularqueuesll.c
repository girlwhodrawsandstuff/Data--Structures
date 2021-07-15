/* implementation of a circular queue using singly linked list */

#include <stdio.h>
#include <stdlib.h>

void addToQueue();

struct node {
    int data;
    struct node * next;
};

struct node * front = 0;
struct node * rear = 0;

void main() {
    addToQueue(5);
}

void addToQueue(int value) {
    struct node * newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> next = 0;

    if(front == 0) {
        front = rear = newNode;
        rear -> next = front;
        printf("'%d' added to the queue.\n", rear -> data);
    } else {
        rear -> next = newNode;
        rear = newNode;
        rear -> next = front;
        printf("'%d' added to the queue.\n", rear -> data);
    }
}