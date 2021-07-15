/* implementation of a circular queue using singly linked list */

#include <stdio.h>
#include <stdlib.h>

void addToQueue();
void deleteFromQueue();
void displayElements();

struct node {
    int data;
    struct node * next;
};

struct node * front = 0;
struct node * rear = 0;

void main() {
    addToQueue(5);
    addToQueue(10);
    deleteFromQueue();
    addToQueue(15);
    displayElements();
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

void deleteFromQueue() {
    struct node * temp;
    temp = front;

    if(front == 0) {
        printf("The queue is empty.\n");
    } else if(front == rear) {
        printf("The value '%d' was deleted.\n", temp -> data);
        front = rear = 0;
        free(temp);
        printf("The queue is now empty.\n");
    } else {
        printf("The value '%d' was deleted.\n", temp -> data);
        front = front -> next;
        rear -> next = front;
        free(temp);
    }
}

void displayElements() {
    struct node * temp;
    temp = front;

    if(front == 0) {
        printf("The queue is empty.\n");
    } else {
        printf("The elements are:\n");
        while(temp -> next != front) {
            printf("%d\n", temp -> data);
            temp = temp -> next;
        }
        printf("%d\n", temp -> data);
    }
}